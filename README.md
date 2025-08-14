3drenderer is 3D Computer Graphics Programming from Pikuma, https://pikuma.com/ by Professor Gustavo Pezzi 

Information about Wavefront .obj file - https://en.wikipedia.org/wiki/Wavefront_.obj_file

Linux Compile Using GCC version 8.5.0 (Released in 2018), the most recent GCC has linker error due to multiple definition 
gcc (GCC) 8.5.0
Copyright (C) 2018 Free Software Foundation, Inc.

The newer GCC compiler is more restricted when defining multiples variables

Recommended Compiler: GCC-8 or GCC-9.
Requirement: GCC command need to be changed in your Makefile to compile correctly.

The newer versions of GCC (like GCC 10, 11, 12, and up) are stricter and more standards-compliant, especially when using flags like -std=c99, -Wall, or -Werror.
🔍 Why Newer GCC Is More Restrictive
🧠 Reason:

Modern GCC adheres more strictly to the C standard (ISO C), which enforces the One Definition Rule (ODR):

    ✅ A global variable can be defined in only one translation unit (i.e., .c file), but can be declared in many.

If you define the same variable in multiple .c files — even if it’s the same name and type — the linker will fail with:

multiple definition of 'my_variable'


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

✅ What Changed in Newer GCC
Version	Behavior on Multiple Global Definitions
Older GCC (pre-9)	Often allowed it silently (undefined behavior)
GCC 9+ and later	Strictly enforces ODR → linker errors

If you are using GCC 13 and still having issue with the linker please apply the solution below
on the `display.h` file

```c
typedef enum cull_method {                                                                                                                                                                                                             
    CULL_NONE,                                                                                                                                                                                                                         
    CULL_BACKFACE,                                                                                                                                                                                                                     
    CULL_FRONTFACE                                                                                                                                                                                                                     
}CullMethod;                                                                                                                                                                                                                           
                                                                                                                                                                                                                                       
// Declare the variable (only a declaration, not a definition)                                                                                                                                                                         
extern CullMethod cull_method;                                                                                                                                                                                                         
                                                                                                                                                                                                                                       
typedef enum render_method {                                                                                                                                                                                                           
    RENDER_WIRE,                                                                                                                                                                                                                       
    RENDER_WIRE_VERTEX,                                                                                                                                                                                                                
    RENDER_FILL_TRIANGLE,                                                                                                                                                                                                              
    RENDER_FILL_TRIANGLE_WIRE,                                                                                                                                                                                                         
    RENDER_TEXTURED,                                                                                                                                                                                                                   
    RENDER_TEXTURED_WIRE                                                                                                                                                                                                               
}RenderMethod;                                                                                                                                                                                                                         
                                                                                                                                                                                                                                       
extern RenderMethod render_method;   
```
And on the `main.c` file you can declared both variable before using them: 

```c
CullMethod cull_method = CULL_NONE;                                                                                                                                                                                                    
RenderMethod render_method;  

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

Recomended fix for missing M_PI variable is to create constant M_PI variable in the `main.c` file
const float M_PI=3.141592653589793;
