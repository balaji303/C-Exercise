/****************************************************************************
 *                                                                          *
 * File    : resizer.c                                                      *
 *                                                                          *
 * Purpose : Pelles C Resizable Dialog Manager implementation.              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include <wchar.h>
#include "xresizer.h"

#define ROUNDUP(n,m)  (((n)+((m)-1)) & (~((m)-1)))

#define RT_DIALOGA  MAKEINTRESOURCEA(5)
#define RT_DIALOGW  MAKEINTRESOURCEW(5)

// Macros to set and retrieve the original window procedure in a subclassed window.
#define SETPROP_WNDPROC(hwnd,pfn)  SetProp((hwnd), PROP_WNDPROC, (HANDLE)(pfn))
#define GETPROP_WNDPROC(hwnd)  ((WNDPROC)GetProp((hwnd), PROP_WNDPROC))
#define REMOVEPROP_WNDPROC(hwnd)  RemoveProp((hwnd), PROP_WNDPROC)

// Macros to set and retrieve the RESIZER pointer in a subclassed window.
#define SETPROP_RESIZER(hwnd,pr)  SetProp((hwnd), PROP_RESIZER, (HANDLE)(pr))
#define GETPROP_RESIZER(hwnd)  ((PRESIZER)GetProp((hwnd), PROP_RESIZER))
#define REMOVEPROP_RESIZER(hwnd)  RemoveProp((hwnd), PROP_RESIZER)

// Integer properties for above.
#define PROP_WNDPROC  MAKEINTATOM(g_atPropWndProc)
#define PROP_RESIZER  MAKEINTATOM(g_atPropResizer)

#ifndef HANDLE_WM_SIZING
/* BOOL onSizing(HWND hwnd, UINT fSize, PRECT prc) */
#define HANDLE_WM_SIZING(hwnd,wParam,lParam,fn)  ((fn)((hwnd), (UINT)(wParam), (PRECT)(lParam)))
#endif /* HANDLE_WM_SIZING */

typedef struct DLGTEMPLATEEX {
    WORD dlgVer;
    WORD signature;
    DWORD helpID;
    DWORD exStyle;
    DWORD style;
    WORD cDlgItems;
    short x;
    short y;
    short cx;
    short cy;
    WORD menu;
    /* sz_Or_Ord menu; */
    /* sz_Or_Ord windowClass; */
    /* WCHAR title[titleLen]; */
    /* WORD pointsize; */
    /* WORD weight; */
    /* BYTE italic; */
    /* BYTE charset; */
    /* WCHAR typeface[stringLen]; */
} DLGTEMPLATEEX, *LPDLGTEMPLATEEX;
typedef const struct DLGTEMPLATEEX *LPCDLGTEMPLATEEX;

typedef struct DLGITEMTEMPLATEEX {
    DWORD helpID;
    DWORD exStyle;
    DWORD style;
    short x;
    short y;
    short cx;
    short cy;
    DWORD id;
    WORD windowClass;
    /* sz_Or_Ord windowClass; */
    /* sz_Or_Ord title; */
    /* WORD extraCount; */
} DLGITEMTEMPLATEEX, *LPDLGITEMTEMPLATEEX;
typedef const struct DLGITEMTEMPLATEEX *LPCDLGITEMTEMPLATEEX;

// Global variables.
static ATOM g_atPropWndProc;
static ATOM g_atPropResizer;
static PRESIZER g_pResizer;  /* for modal dialog */
static DLGPROC g_pfnDialog;  /* original dialog proc, for modal dialog */

// Static function prototypes.
static size_t NameOrdLenW(PCWSTR);
static BOOL MakeResizableDialog(LPCDLGTEMPLATEW, LPDLGTEMPLATEW *, PRESIZER *);
static SIZE_T SizeOfExtendedTemplate(LPCDLGTEMPLATEW);
static BOOL InstallResizableDialogHandler(HWND, PRESIZER);
static INT_PTR CALLBACK ResizerDlgProc(HWND, UINT, WPARAM, LPARAM);
static LRESULT CALLBACK ResizerWndProc(HWND, UINT, WPARAM, LPARAM);
static void Resizer_OnGetMinMaxInfo(HWND, PMINMAXINFO);
static UINT Resizer_OnNCHitTest(HWND, int, int);
static BOOL Resizer_OnSizing(HWND, UINT, PRECT);
static void Resizer_OnSize(HWND, UINT, int, int);
static BOOL Resizer_OnEraseBkgnd(HWND, HDC);
static void Resizer_OnDestroy(HWND);
static void MoveDialogControls(HWND, int, int);
static void GetAdjustedControlRect(PRECT, HWND, HWND, const RESIZERCTL *, int, int);
static void GetGripperRect(HWND, PRECT);

// Inline functions (one-liners).
static inline int RectHeight(const RECT *prc) { return prc->bottom - prc->top; }
static inline int RectWidth(const RECT *prc) { return prc->right - prc->left; }
static inline BOOL IsOrdinalW(PCWSTR pwch) { return (pwch[0] == (WCHAR)-1) ? TRUE : FALSE; }
static inline PVOID DWordAlign(const void *pv) { return (PVOID)ROUNDUP((DWORD_PTR)pv, sizeof(DWORD)); }
static inline PVOID AppendBlock(void *pvDst, const void *pvSrc, size_t cbSrc) { return (PBYTE)memcpy(pvDst, pvSrc, cbSrc) + cbSrc; }
static inline PVOID MyAlloc(SIZE_T cb) { return HeapAlloc(GetProcessHeap(), 0, cb); }
static inline void MyFree(PVOID pv) { if (pv) HeapFree(GetProcessHeap(), 0, pv); }

/****************************************************************************
 *                                                                          *
 * Function: AdjustResizableDialog                                          *
 *                                                                          *
 * Purpose : Adjust resizable dialog size without moving controls.          *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

BOOL WINAPI AdjustResizableDialog(HWND hwndDlg, int dx, int dy)
{
    PRESIZER pResizer;

    pResizer = GETPROP_RESIZER(hwndDlg);
    if (pResizer != NULL)
    {
        RECT rc;

        pResizer->fEnabled = FALSE;  /* sorry, on vacation */

        GetWindowRect(hwndDlg, &rc);
        SetWindowPos(hwndDlg, NULL, 0, 0, RectWidth(&rc) + dx, RectHeight(&rc) + dy, SWP_NOMOVE|SWP_NOZORDER|SWP_NOCOPYBITS);

        pResizer->sizeMinTrack.cx += dx;
        pResizer->sizeMinTrack.cy += dy;
        pResizer->sizeMinClient.cx += dx;
        pResizer->sizeMinClient.cy += dy;
        pResizer->sizeCurClient.cx += dx;
        pResizer->sizeCurClient.cy += dy;

        pResizer->fEnabled = TRUE;  /* OK, I'm back */

        return TRUE;
    }

    return FALSE;
}

/****************************************************************************
 *                                                                          *
 * Function: CreateResizableDialogParamA                                    *
 *                                                                          *
 * Purpose : Like CreateDialogParamA(), but for a resizable dialog.         *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

HWND WINAPI CreateResizableDialogParamA(HINSTANCE hInst, PCSTR pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    HRSRC hrsrc;
    HGLOBAL hgRes;
    PVOID pvRes;

    if ((hrsrc = FindResourceA(hInst, pTemplate, RT_DIALOGA)) != NULL &&
        (hgRes = LoadResource(hInst, hrsrc)) != NULL &&
        (pvRes = LockResource(hgRes)) != NULL)
    {
        return CreateResizableDialogIndirectParamA(hInst, pvRes, hwndParent, pfnDialog, lParam);
    }
    else
    {
        return CreateDialogParamA(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }
}

/****************************************************************************
 *                                                                          *
 * Function: CreateResizableDialogParamW                                    *
 *                                                                          *
 * Purpose : Like CreateDialogParamW(), but for a resizable dialog.         *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

HWND WINAPI CreateResizableDialogParamW(HINSTANCE hInst, PCWSTR pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    HRSRC hrsrc;
    HGLOBAL hgRes;
    PVOID pvRes;

    if ((hrsrc = FindResourceW(hInst, pTemplate, RT_DIALOGW)) != NULL &&
        (hgRes = LoadResource(hInst, hrsrc)) != NULL &&
        (pvRes = LockResource(hgRes)) != NULL)
    {
        return CreateResizableDialogIndirectParamW(hInst, pvRes, hwndParent, pfnDialog, lParam);
    }
    else
    {
        return CreateDialogParamW(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }
}

/****************************************************************************
 *                                                                          *
 * Function: CreateResizableDialogIndirectParamA                            *
 *                                                                          *
 * Purpose : Like CreateDialogIndirectParamA(), but for a resizable dialog. *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

HWND WINAPI CreateResizableDialogIndirectParamA(HINSTANCE hInst, LPCDLGTEMPLATEW pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    LPDLGTEMPLATE pNewTemplate;
    PRESIZER pResizer;
    HWND hwndDlg;

    if (MakeResizableDialog(pTemplate, &pNewTemplate, &pResizer))
    {
        hwndDlg = CreateDialogIndirectParamA(hInst, pNewTemplate, hwndParent, pfnDialog, lParam);
        if (hwndDlg != NULL)
        {
            InstallResizableDialogHandler(hwndDlg, pResizer);
            InvalidateRect(hwndDlg, NULL, TRUE);  /* makes Vista happier than expected... */
        }

        MyFree(pNewTemplate);
        // pResizer free'd elsewhere.
    }
    else
    {
        hwndDlg = CreateDialogIndirectParamA(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }

    return hwndDlg;
}

/****************************************************************************
 *                                                                          *
 * Function: CreateResizableDialogIndirectParamW                            *
 *                                                                          *
 * Purpose : Like CreateDialogIndirectParamW(), but for a resizable dialog. *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

HWND WINAPI CreateResizableDialogIndirectParamW(HINSTANCE hInst, LPCDLGTEMPLATEW pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    LPDLGTEMPLATE pNewTemplate;
    PRESIZER pResizer;
    HWND hwndDlg;

    if (MakeResizableDialog(pTemplate, &pNewTemplate, &pResizer))
    {
        hwndDlg = CreateDialogIndirectParamW(hInst, pNewTemplate, hwndParent, pfnDialog, lParam);
        if (hwndDlg != NULL)
        {
            InstallResizableDialogHandler(hwndDlg, pResizer);
            InvalidateRect(hwndDlg, NULL, TRUE);  /* makes Vista happier than expected... */
        }

        MyFree(pNewTemplate);
        // pResizer free'd elsewhere.
    }
    else
    {
        hwndDlg = CreateDialogIndirectParamW(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }

    return hwndDlg;
}

/****************************************************************************
 *                                                                          *
 * Function: ResizableDialogBoxParamA                                       *
 *                                                                          *
 * Purpose : Like DialogBoxParamA(), but for a resizable dialog.            *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

INT_PTR WINAPI ResizableDialogBoxParamA(HINSTANCE hInst, PCSTR pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    HRSRC hrsrc;
    HGLOBAL hgRes;
    PVOID pvRes;

    if ((hrsrc = FindResourceA(hInst, pTemplate, RT_DIALOGA)) != NULL &&
        (hgRes = LoadResource(hInst, hrsrc)) != NULL &&
        (pvRes = LockResource(hgRes)) != NULL)
    {
        return ResizableDialogBoxIndirectParamA(hInst, pvRes, hwndParent, pfnDialog, lParam);
    }
    else
    {
        return DialogBoxParamA(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }
}

/****************************************************************************
 *                                                                          *
 * Function: ResizableDialogBoxParamW                                       *
 *                                                                          *
 * Purpose : Like DialogBoxParamW(), but for a resizable dialog.            *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

INT_PTR WINAPI ResizableDialogBoxParamW(HINSTANCE hInst, PCWSTR pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    HRSRC hrsrc;
    HGLOBAL hgRes;
    PVOID pvRes;

    if ((hrsrc = FindResourceW(hInst, pTemplate, RT_DIALOGW)) != NULL &&
        (hgRes = LoadResource(hInst, hrsrc)) != NULL &&
        (pvRes = LockResource(hgRes)) != NULL)
    {
        return ResizableDialogBoxIndirectParamW(hInst, pvRes, hwndParent, pfnDialog, lParam);
    }
    else
    {
        return DialogBoxParamW(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }
}

/****************************************************************************
 *                                                                          *
 * Function: ResizableDialogBoxIndirectParamA                               *
 *                                                                          *
 * Purpose : Like DialogBoxIndirectParamA(), but for a resizable dialog.    *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

INT_PTR WINAPI ResizableDialogBoxIndirectParamA(HINSTANCE hInst, LPCDLGTEMPLATEA pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    LPDLGTEMPLATE pNewTemplate;
    PRESIZER pResizer;
    INT_PTR result;

    if (MakeResizableDialog(pTemplate, &pNewTemplate, &pResizer))
    {
        // Warning! Global variables.
        g_pResizer = pResizer;
        g_pfnDialog = pfnDialog;

        result = DialogBoxIndirectParamA(hInst, pNewTemplate, hwndParent, ResizerDlgProc, lParam);

        MyFree(pNewTemplate);
        // pResizer free'd elsewhere.
    }
    else
    {
        result = DialogBoxIndirectParamA(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }

    return result;
}

/****************************************************************************
 *                                                                          *
 * Function: ResizableDialogBoxIndirectParamW                               *
 *                                                                          *
 * Purpose : Like DialogBoxIndirectParamW(), but for a resizable dialog.    *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

INT_PTR WINAPI ResizableDialogBoxIndirectParamW(HINSTANCE hInst, LPCDLGTEMPLATEW pTemplate, HWND hwndParent, DLGPROC pfnDialog, LPARAM lParam)
{
    LPDLGTEMPLATE pNewTemplate;
    PRESIZER pResizer;
    INT_PTR result;

    if (MakeResizableDialog(pTemplate, &pNewTemplate, &pResizer))
    {
        // Warning! Global variables.
        g_pResizer = pResizer;
        g_pfnDialog = pfnDialog;

        result = DialogBoxIndirectParamW(hInst, pNewTemplate, hwndParent, ResizerDlgProc, lParam);

        MyFree(pNewTemplate);
        // pResizer free'd elsewhere.
    }
    else
    {
        result = DialogBoxIndirectParamW(hInst, pTemplate, hwndParent, pfnDialog, lParam);
    }

    return result;
}

/****************************************************************************
 *                                                                          *
 * Function: MakeResizableDialog                                            *
 *                                                                          *
 * Purpose : Process dialog template for a resizable dialog.                *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static BOOL MakeResizableDialog(LPCDLGTEMPLATEW pTemplate, LPDLGTEMPLATE *ppNewTemplate, PRESIZER *ppResizer)
{
    LPCDLGTEMPLATEEX pDlg = (LPCDLGTEMPLATEEX)pTemplate;
    SIZE_T cbTemplate;

    // Calculate size of (extended) dialog template.
    if ((cbTemplate = SizeOfExtendedTemplate(pTemplate)) != 0)
    {
        LPDLGTEMPLATEEX pNewTemplate = NULL;
        PRESIZER pResizer = NULL;

        // Allocate memory (worst case for template and control array).
        if ((pNewTemplate = MyAlloc(cbTemplate)) != NULL &&
            (pResizer = MyAlloc(sizeof(*pResizer))) != NULL &&
            (pResizer->pControls = MyAlloc(pDlg->cDlgItems * sizeof(*pResizer->pControls))) != NULL)
        {
            PVOID pvNew = pNewTemplate;
            const VOID *pv = &pDlg->menu;
            WORD i;

            // Skip menu.
            pv = (PBYTE)pv + NameOrdLenW(pv);

            // Skip class.
            pv = (PBYTE)pv + NameOrdLenW(pv);

            // Skip window title.
            pv = (PBYTE)pv + NameOrdLenW(pv);

            // Font specification present?
            if ((pDlg->style & DS_SETFONT) != 0)
            {
                // Skip point size.
                pv = (PBYTE)pv + sizeof(WORD);

                // Skip weight.
                pv = (PBYTE)pv + sizeof(WORD);

                // Skip italic.
                pv = (PBYTE)pv + sizeof(BYTE);

                // Skip charset.
                pv = (PBYTE)pv + sizeof(BYTE);

                // Skip typeface.
                pv = (PBYTE)pv + NameOrdLenW(pv);
            }

            // Align.
            pv = DWordAlign(pv);

            // Append part to new template.
            pvNew = AppendBlock(pvNew, pDlg, (PBYTE)pv - (PBYTE)pDlg);

            // Process the controls.
            pResizer->cControls = 0;
            for (i = 0; i < pDlg->cDlgItems; i++)
            {
                LPCDLGITEMTEMPLATEEX pCtl = pv;
                PCEXTRADATA pExtraData;
                DWORD cbExtraData;

                pv = &pCtl->windowClass;

                // Skip window class.
                pv = (PBYTE)pv + NameOrdLenW(pv);

                // Skip window title.
                pv = (PBYTE)pv + NameOrdLenW(pv);

                // Append part to new template.
                pvNew = AppendBlock(pvNew, pCtl, (PBYTE)pv - (PBYTE)pCtl);

                // Process control creation data.
                cbExtraData = *(PWORD)pv;
                pv = (PBYTE)pv + sizeof(WORD);
                pExtraData = pv;
                pv = (PBYTE)pv + cbExtraData;

                // Look for our version of "creation data".
                if (cbExtraData == sizeof(*pExtraData) && pExtraData->magic == EXTRA_MAGIC && pExtraData->version == EXTRA_VERSION)
                {
                    // Avoid "nameless" controls.
                    if (pCtl->id != -1U)
                    {
                        // Found a control to handle during resize.
                        int k = pResizer->cControls++;
                        pResizer->pControls[k].id = pCtl->id;
                        pResizer->pControls[k].fuAlign = pExtraData->fuAlign;
                    }

                    // Strip away creation data.
                    *(PWORD)pvNew = 0;
                    pvNew = (PBYTE)pvNew + sizeof(WORD);
                }
                else
                {
                    // Append user-defined creation data.
                    *(PWORD)pvNew = cbExtraData;
                    pvNew = (PBYTE)pvNew + sizeof(WORD);
                    pvNew = AppendBlock(pvNew, pExtraData, cbExtraData);
                }

                // Align.
                pvNew = DWordAlign(pvNew);
                pv = DWordAlign(pv);
            }

            if (pResizer->cControls > 0)
            {
                // Make the dialog resizable.
                pNewTemplate->style |= WS_THICKFRAME;

                // Return to the happy caller.
                *ppNewTemplate = (DLGTEMPLATE *)pNewTemplate;
                *ppResizer = pResizer;
                return TRUE;
            }

            // Clean up.
            MyFree(pResizer->pControls);
            MyFree(pResizer);
        }

        // Clean up.
        MyFree(pNewTemplate);
    }

    // Return to the (soon to be) unhappy caller.
    *ppNewTemplate = NULL;
    *ppResizer = NULL;
    return FALSE;
}

/****************************************************************************
 *                                                                          *
 * Function: SizeOfExtendedTemplate                                         *
 *                                                                          *
 * Purpose : Return length of extended dialog template, else zero.          *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static SIZE_T SizeOfExtendedTemplate(LPCDLGTEMPLATEW pTemplate)
{
    LPCDLGTEMPLATEEX pDlg = (LPCDLGTEMPLATEEX)pTemplate;

    // Must have an extended dialog.
    if (pDlg->signature == 0xFFFF && pDlg->dlgVer == 1)
    {
        const VOID *pv = &pDlg->menu;
        WORD i;

        // Skip menu.
        pv = (PBYTE)pv + NameOrdLenW(pv);

        // Skip class.
        pv = (PBYTE)pv + NameOrdLenW(pv);

        // Skip window title.
        pv = (PBYTE)pv + NameOrdLenW(pv);

        // Font specification present?
        if ((pDlg->style & DS_SETFONT) != 0)
        {
            // Skip point size.
            pv = (PBYTE)pv + sizeof(WORD);

            // Skip weight.
            pv = (PBYTE)pv + sizeof(WORD);

            // Skip italic.
            pv = (PBYTE)pv + sizeof(BYTE);

            // Skip charset.
            pv = (PBYTE)pv + sizeof(BYTE);

            // Skip typeface.
            pv = (PBYTE)pv + NameOrdLenW(pv);
        }

        // Align.
        pv = DWordAlign(pv);

        // Process the controls.
        for (i = 0; i < pDlg->cDlgItems; i++)
        {
            LPCDLGITEMTEMPLATEEX pCtl = pv;

            pv = &pCtl->windowClass;

            // Skip window class.
            pv = (PBYTE)pv + NameOrdLenW(pv);

            // Skip window title.
            pv = (PBYTE)pv + NameOrdLenW(pv);

            // Skip control creation data.
            pv = (PBYTE)pv + sizeof(WORD) + *(PWORD)pv;

            // Align.
            pv = DWordAlign(pv);
        }

        // Return the size, in bytes.
        return (PBYTE)pv - (PBYTE)pTemplate;
    }

    // Very, very, small.
    return 0;
}

/****************************************************************************
 *                                                                          *
 * Function: NameOrdLenW                                                    *
 *                                                                          *
 * Purpose : Return length of name/ordinal value.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static size_t NameOrdLenW(PCWSTR pwchNameOrd)
{
    if (IsOrdinalW(pwchNameOrd))
        return 2 * sizeof(WCHAR);
    else
        return (wcslen(pwchNameOrd)+1) * sizeof(WCHAR);
}

/****************************************************************************
 *                                                                          *
 * Function: MakeDialogResizable                                            *
 *                                                                          *
 * Purpose : Make the given dialog resizable; Call from WM_INITDIALOG.      *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static BOOL InstallResizableDialogHandler(HWND hwndDlg, PRESIZER pResizer)
{
    RECT rc;

    // Something to hang our hat on...
    g_atPropWndProc = GlobalAddAtomW(L"ResizerWindowProc");
    g_atPropResizer = GlobalAddAtomW(L"ResizerPointer");

    // The minimum dialog size is the original size.
    GetWindowRect(hwndDlg, &rc);
    pResizer->sizeMinTrack.cx = RectWidth(&rc);
    pResizer->sizeMinTrack.cy = RectHeight(&rc);
    GetClientRect(hwndDlg, &rc);
    pResizer->sizeMinClient.cx = RectWidth(&rc);
    pResizer->sizeMinClient.cy = RectHeight(&rc);
    pResizer->sizeCurClient.cx = RectWidth(&rc);
    pResizer->sizeCurClient.cy = RectHeight(&rc);
    pResizer->fEnabled = TRUE;

    // Subclass the dialog.
    SETPROP_WNDPROC(hwndDlg, SubclassWindow(hwndDlg, ResizerWndProc));
    SETPROP_RESIZER(hwndDlg, pResizer);

    // Happy? Really?!
    return GETPROP_WNDPROC(hwndDlg) != NULL && GETPROP_RESIZER(hwndDlg) != NULL;
}

/****************************************************************************
 *                                                                          *
 * Function: ResizerDlgProc                                                 *
 *                                                                          *
 * Purpose : Handle messages for modal resizable dialog.                    *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static INT_PTR CALLBACK ResizerDlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_INITDIALOG && g_pResizer != NULL)
    {
        // Install handler after processing WM_INIDIALOG;
        // not optimal, but consistent with modeless dialogs.
        INT_PTR result = (*g_pfnDialog)(hwndDlg, msg, wParam, lParam);
        InstallResizableDialogHandler(hwndDlg, g_pResizer);
        g_pResizer = NULL;
        return result;
    }
    return (*g_pfnDialog)(hwndDlg, msg, wParam, lParam);
}

/****************************************************************************
 *                                                                          *
 * Function: ResizerWndProc                                                 *
 *                                                                          *
 * Purpose : Handle messages for subclassed resizable dialog.               *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static LRESULT CALLBACK ResizerWndProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        HANDLE_MSG(hwndDlg, WM_GETMINMAXINFO, Resizer_OnGetMinMaxInfo);
        HANDLE_MSG(hwndDlg, WM_NCHITTEST, Resizer_OnNCHitTest);
        HANDLE_MSG(hwndDlg, WM_SIZING, Resizer_OnSizing);
        HANDLE_MSG(hwndDlg, WM_SIZE, Resizer_OnSize);
        HANDLE_MSG(hwndDlg, WM_ERASEBKGND, Resizer_OnEraseBkgnd);
        HANDLE_MSG(hwndDlg, WM_DESTROY, Resizer_OnDestroy);
    }

    // Send to the original procedure.
    return CallWindowProc(GETPROP_WNDPROC(hwndDlg), hwndDlg, msg, wParam, lParam);
}

/****************************************************************************
 *                                                                          *
 * Function: Resizer_OnGetMinMaxInfo                                        *
 *                                                                          *
 * Purpose : Handle WM_GETMINMAXINFO message.                               *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static void Resizer_OnGetMinMaxInfo(HWND hwndDlg, PMINMAXINFO pmmi)
{
    PRESIZER pResizer;

    pResizer = GETPROP_RESIZER(hwndDlg);
    if (pResizer != NULL && pResizer->fEnabled)
    {
        // Set the minimum tracking size.
        pmmi->ptMinTrackSize.x = pResizer->sizeMinTrack.cx;
        pmmi->ptMinTrackSize.y = pResizer->sizeMinTrack.cy;
    }
}

/****************************************************************************
 *                                                                          *
 * Function: Resizer_OnNCHitTest                                            *
 *                                                                          *
 * Purpose : Handle WM_NCHITTEST message.                                   *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static UINT Resizer_OnNCHitTest(HWND hwndDlg, int x, int y)
{
    int cx, cy;
    RECT rc;

    GetGripperRect(hwndDlg, &rc);
    MapWindowRect(hwndDlg, NULL, &rc);
    cx = x - rc.left;
    cy = y - rc.top;
    if (cx > 0 && cy > 0 && RectWidth(&rc) < cx + cy)
        return HTBOTTOMRIGHT;

    return (UINT)CallWindowProc(GETPROP_WNDPROC(hwndDlg), hwndDlg, WM_NCHITTEST, 0, MAKELPARAM(x,y));
}

/****************************************************************************
 *                                                                          *
 * Function: Resizer_OnSizing                                               *
 *                                                                          *
 * Purpose : Handle WM_SIZING message.                                      *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static BOOL Resizer_OnSizing(HWND hwndDlg, UINT fSize, PRECT prc)
{
    BOOL fResult;
    RECT rc;

    fResult = (BOOL)CallWindowProc(GETPROP_WNDPROC(hwndDlg), hwndDlg, WM_SIZING, (WPARAM)fSize, (LPARAM)prc);

    GetGripperRect(hwndDlg, &rc);
    InvalidateRect(hwndDlg, &rc, FALSE);

    return fResult;
}

/****************************************************************************
 *                                                                          *
 * Function: Resizer_OnSize                                                 *
 *                                                                          *
 * Purpose : Handle WM_SIZE message.                                        *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static void Resizer_OnSize(HWND hwndDlg, UINT state, int cx, int cy)
{
    (void)CallWindowProc(GETPROP_WNDPROC(hwndDlg), hwndDlg, WM_SIZE, (WPARAM)state, MAKELPARAM(cx, cy));

    if (state != SIZE_MINIMIZED)
    {
        RECT rc;

        MoveDialogControls(hwndDlg, cx, cy);

        GetGripperRect(hwndDlg, &rc);
        InvalidateRect(hwndDlg, &rc, TRUE);
    }
}

/****************************************************************************
 *                                                                          *
 * Function: Resizer_OnEraseBkgnd                                           *
 *                                                                          *
 * Purpose : Handle WM_ERASEBKGND message.                                  *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static BOOL Resizer_OnEraseBkgnd(HWND hwndDlg, HDC hdc)
{
    BOOL fResult;
    RECT rc;

    fResult = (BOOL)CallWindowProc(GETPROP_WNDPROC(hwndDlg), hwndDlg, WM_ERASEBKGND, (WPARAM)hdc, 0);

    GetGripperRect(hwndDlg, &rc);
    DrawFrameControl(hdc, &rc, DFC_SCROLL, DFCS_SCROLLSIZEGRIP);

    return fResult;
}

/****************************************************************************
 *                                                                          *
 * Function: Resizer_OnDestroy                                              *
 *                                                                          *
 * Purpose : Handle WM_DESTROY message.                                     *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static void Resizer_OnDestroy(HWND hwndDlg)
{
    // Clean up.
    PRESIZER pResizer = GETPROP_RESIZER(hwndDlg);
    MyFree(pResizer->pControls);
    MyFree(pResizer);
    REMOVEPROP_RESIZER(hwndDlg);
    pResizer = NULL;

    CallWindowProc(GETPROP_WNDPROC(hwndDlg), hwndDlg, WM_DESTROY, 0, 0);
    SubclassWindow(hwndDlg, GETPROP_WNDPROC(hwndDlg));
    REMOVEPROP_WNDPROC(hwndDlg);

    GlobalDeleteAtom(g_atPropWndProc);
    GlobalDeleteAtom(g_atPropResizer);
}

/****************************************************************************
 *                                                                          *
 * Function: MoveDialogControls                                             *
 *                                                                          *
 * Purpose : Move dialog controls to new locations.                         *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static void MoveDialogControls(HWND hwndDlg, int cx, int cy)
{
    PRESIZER pResizer;

    pResizer = GETPROP_RESIZER(hwndDlg);
    if (pResizer != NULL && pResizer->fEnabled)
    {
        HDWP hdwp;

        hdwp = BeginDeferWindowPos(pResizer->cControls);
        if (hdwp != NULL)
        {
            int dx, dy;
            int i;

            // Make sure we don't go below the minimum dialog size.
            cx = max(cx, pResizer->sizeMinClient.cx);
            cy = max(cy, pResizer->sizeMinClient.cy);

            // Calculate deltas.
            dx = cx - pResizer->sizeCurClient.cx;
            dy = cy - pResizer->sizeCurClient.cy;

            // Remember for next time.
            pResizer->sizeCurClient.cx = cx;
            pResizer->sizeCurClient.cy = cy;

            // Move all controls.
            for (i = 0; i < pResizer->cControls; i++)
            {
                PCRESIZERCTL pCtl = &pResizer->pControls[i];
                HWND hwndCtl;

                hwndCtl = GetDlgItem(hwndDlg, pCtl->id);
                if (hwndCtl != NULL)
                {
                    RECT rc;

                    // Get adjusted rectangle, then move or resize the dialog control window.
                    GetAdjustedControlRect(&rc, hwndDlg, hwndCtl, pCtl, dx, dy);
                    hdwp = DeferWindowPos(hdwp, hwndCtl, NULL, rc.left, rc.top, RectWidth(&rc), RectHeight(&rc), SWP_NOZORDER);
                }
            }

            EndDeferWindowPos(hdwp);
        }
    }
}

/****************************************************************************
 *                                                                          *
 * Function: GetAdjustedControlRect                                         *
 *                                                                          *
 * Purpose : Get adjusted dialog control rectangle, in screen coordinates.  *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static void GetAdjustedControlRect(PRECT prc, HWND hwndDlg, HWND hwndCtl, PCRESIZERCTL pCtl, int dx, int dy)
{
    // Get the current window rectangle.
    GetWindowRect(hwndCtl, prc);
    MapWindowRect(NULL, hwndDlg, prc);

    // Apply previously calculated deltas.
    if (pCtl->fuAlign & RESIZER_LEFT) prc->left += dx;
    if (pCtl->fuAlign & RESIZER_RIGHT) prc->right += dx;
    if (pCtl->fuAlign & RESIZER_TOP) prc->top += dy;
    if (pCtl->fuAlign & RESIZER_BOTTOM) prc->bottom += dy;
}

/****************************************************************************
 *                                                                          *
 * Function: GetGripperRect                                                 *
 *                                                                          *
 * Purpose : Get gripper rectangle, in client coords.                       *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

static void GetGripperRect(HWND hwndDlg, PRECT prc)
{
    GetClientRect(hwndDlg, prc);
    prc->left = prc->right - GetSystemMetrics(SM_CXVSCROLL);
    prc->top = prc->bottom - GetSystemMetrics(SM_CXVSCROLL);
}
