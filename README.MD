<!-----------------------------------------------------------------
Name: Jaylan Pierce
 Project: SIC/XE Disassembler
--------------------------------------------------------------------->

## SIC/XE Disassembler
### Developed by Jaylan Pierce

#### Synopsis
    Designed and implemented a dissamebler for the XE varieant of the SIC/XE architecture. The disassembler is able to open a given object code file (.obj) along with a symbol file (.sym) and disassembles the object coe and prints to an output file (out.lst).

#### Files Included:
**README.md**:

    A README file describing the program and detailing its files.

**dissem.cpp**:
    File contains algorithm that opens a SIC/XE object file and symbol file. The object code is disassembled and generates SIC/XE source and listing files.

**dissem.hpp**:
    Declares and explains functions implemented in dissem.cpp

**Makefile**:
    Creates a compiled version of dissem.cpp

#### Compilation Instructions:
**Make**:
    make:
        compiles the dissem file

    make clean:
        removes dissem and out.lst files

**Running the Program**:
./dissem <file1> <file2>

#### Inputs:
    File 1: Must be an .obj file
    File 2: Must be an .sym file

#### Known Bugs:
    There is a bug in outputWrite() starting on line 898. For the given inputs 'RETADR' is
    supposed to be stored after line 911 but '008' is stored instead. It has something to
    do with the way I stored the objectVector[]. This bug causes the rest of of program
    after to be slightly off from what is shown in the given input.