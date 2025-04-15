Information about Wavefront .obj file - https://en.wikipedia.org/wiki/Wavefront_.obj_file

Linux Compile Using GCC version 8.5.0 (Released in 2018), the most recent GCC has linker error due to multiple definition 
gcc (GCC) 8.5.0
Copyright (C) 2018 Free Software Foundation, Inc.

C linking error caused by defining global variables in multiple .c files.  (This include enum declaration and multiple enum definitions in the new GCC)
If you're using enum in C and running into multiple definition errors with newer versions of GCC. // BAD: this is a global definition in multiple files
Because each file that compiles this line creates its own copy of the variables.
So to avoid multiple definitions in each .c files, we should not define the variable definition or enum definition in the header file.

```c
num CullMethod {
    CULL_NONE,
    CULL_BACKFACE,
    CULL_FRONTFACE
} cull_method;
```
is not just declaring the enum type, it's also defining a global variable named cull_method.
So if this is in a header file, it is bad practice because:
Every .c file that includes this header will create its own copy of cull_method.
Result: Linker error: "multiple definition of cull_method".

Correct Way (Split Type and Variable) - in the .h file do this
```c
// Define enum type (the safe way)
enum CullMethod {
    CULL_NONE,
    CULL_BACKFACE,
    CULL_FRONTFACE
};

// Declare the variable (only a declaration, not a definition)
extern enum CullMethod cull_method;
```
Correct way in the .c file do this:
```c
// Define the variable in the .c file
enum CullMethod cull_method;
```

===================================================================

MACRO Issue with GNU Systems or when compiling with GCC compiler

In Linux, the math.h header file is part of the standard C library, specifically provided by glibc (GNU C Library)

The math.h is present on the include folder and M_PI is defined, but you're still getting an "M_PI undeclared" error?
That’s a very common issue with GCC Compiler and here’s the reason:

The Fix: Define _GNU_SOURCE or _USE_MATH_DEFINES Before #include <math.h>

Even though M_PI is in math.h, you must enable it by defining certain macros before including math.h

Why This Happens:
M_PI is not part of the ISO C standard.  It’s a GNU extension, so it's only available when _GNU_SOURCE is defined.  
Without defining it, the compiler hides these constants for strict standard compliance.

run this command: 
gcc -Wall -std=c99 -D_GNU_SOURCE ./src/*.c -lSDL2 -lm -o renderer    
