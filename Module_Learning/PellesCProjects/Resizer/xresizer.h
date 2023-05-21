/****************************************************************************
 *                                                                          *
 * File    : xresizer.h                                                     *
 *                                                                          *
 * Purpose : Private definitions for Pelles C Resizable Dialog Manager.     *
 *                                                                          *
 * History : Date      Reason                                               *
 *           09-02-22  Created                                              *
 *                                                                          *
 ****************************************************************************/

#ifndef _XRESIZER_H
#define _XRESIZER_H

#include "resizer.h"

// fuAlign flags.
#define RESIZER_NONE    0x0000
#define RESIZER_LEFT    0x0001
#define RESIZER_RIGHT   0x0002
#define RESIZER_TOP     0x0004
#define RESIZER_BOTTOM  0x0008
#define RESIZER_HORZ    (RESIZER_LEFT|RESIZER_RIGHT)
#define RESIZER_VERT    (RESIZER_TOP|RESIZER_BOTTOM)

typedef struct RESIZERCTL {
    int id;                 // Control id.
    BYTE fuAlign;           // Alignment flags (RESIZER_*).
} RESIZERCTL, *PRESIZERCTL;
typedef const struct RESIZERCTL *PCRESIZERCTL;

typedef struct RESIZER {
    RESIZERCTL *pControls;  // Pointer to array with control info.
    int cControls;          // Number of controls.
    SIZE sizeCurClient;     // Current client area size.
    SIZE sizeMinClient;     // Minimum client area size.
    SIZE sizeMinTrack;      // Minimum window size.
    BOOL fEnabled;
} RESIZER, *PRESIZER;
typedef const struct RESIZER *PCRESIZER;

#define EXTRA_MAGIC    0xC0DE
#define EXTRA_VERSION  1

#include <pshpack2.h>
typedef struct EXTRADATA {
    WORD magic;             // Magic number (EXTRA_MAGIC).
    WORD version;           // Version (EXTRA_VERSION).
    WORD fuAlign;           // Alignment flags.
} EXTRADATA, *PEXTRADATA;
typedef const struct EXTRADATA *PCEXTRADATA;
#include <poppack.h>

#endif /* _XRESIZER_H */
