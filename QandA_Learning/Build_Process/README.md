# Build Process

There are many steps involved from the creation of the C Program to converting it into an executable form.

Many software development tools like Code Blocks, Visual Studio Code in the name of "Manking the process easy" they hide many of these steps and makes us believing that, we are some kind of muggles there are 'magic' that generates the executable code.


## Source Code

These is where it all begans, 

- we create definition for the main function
- Includes libraries
- Call some functions
- Makes some blunder mistakes and clear them ;)

[Monkey GIF]

## Preprocessing

During this step, the C source code is expanded based on the preprocessor directives like #define, #include, etc. The explaneded source code is stored in an intermediate file with .I extension (Captial i).

The extension may vary based on the compiler we use.

## Compilation

The explanded source code is then passed to the compiler[converst high level lang to lower level lang], which identifies the warnings, syntax errors in the source code.

One and only if the code is error-free.[Yes, we all deserve to be here!]. Then the compiler translates the expanded source code in C, into a required assembly language program.

The assembly code is usually stored in .ASM format.

The assembly code for Intel Pentium processor will not run on SnapDragon 888 processor.

## Assembling

As you may have guess the job of assembler is to convert the .ASM file into .OBJ or .O file

The onject file contains a header and several sections. The header describes the sections that follow it.

1. Text section:
        This section contains machine language code equivalent to the expanded source code.

1. Data Section:
        This section global variables and their initial values.

1. BSS section:
        Block Started by Symbol section is the abbrevation. This section contains uninitialized global variables.

1. Symbol Table:
        This section contains information about the symbols found during assembling of the program. Typical information present in the symbol table includes

        - Names, types and sizes of the global vaiables.
        - Names and addressses of function defines in the source code.
        - Names of the external function like printf() and scanf()

As there is machine language instruction and other required files already present in the object file why can't we run this directly?

- Functions like printf() will not be present in the main file's object file. Since it is a library function it is present in the respective object file.

- Same like functions global variables will be used accross many object files.

Which means we need someone to link all these object files together ;)

## Linker

Here we are in the final section of the blog as well as the build process.

Linker combines different data sections of differnet object file into a single data section

while doing this work linker has to address a problem, 

Addresses of all variables and functions in the Symbol Table of the object file are relative addresses. This means that address of a variable or function is in fact only an offset from start of the Section to which it belongs.

For example: In a file app.o if there is one 2 byte global variable volt1 then the Symbol table will have  address 0 for it and if there are two 4 byte global variables count1 and temp1 in main.o file then the Symbol table will have addresses 0 and 4 for them.

When linker combines the two object files, it will re-adjust the addresses of the variables. Thus after doing it the variables 

''' 

        0 = volt1

        2 = count1

        6 = temp1
'''

During linking if the linker detects errors like function type, it creates errors and stops the linking process.

## Exe file creation

In the .exe file, machine language code from all of the input object files will be in the text section. Similarly, all initialized and uninitialized variables will be in the new data and BSS sections.

For executing the .EXE file, it is first fetched and loaded into the Random Access Memory (RAM) by an operating system component called Program Loader.

Since all the address in the .EXE in memory is relative address, we can load it anywhere in RAM.
Once it is loaded, the execution begins from the first instruction in code section of the file loaded in memory.

## End card

Like a object file, a exe file is also formatted binary file. The format of these files differ from one OS to another.

For example, MS Windows uses Portable Executables(PE) file format and Linux uses Executable and Linking format (ELF). Hence the object file or exe created in windows created in windows won't run in Linux and vice-versa.

