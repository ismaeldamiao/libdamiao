## What a directive?

Directives are instructions to preprocessor.
Directives change your code before and the compiler compile the changed code.

For example, if the directive `#define MAX(x, y) x < y ? -x : y` is called
by `a = 2 * MAX(3 + b, 8)` then it exapands the expression to
`a = 2 * 3 + b ? -3 + b : 8` and 2 is multiplied by 3 instead the max. The
correct way of define is `#define MAX(x, y) ((x) < (y) ? -(x) : (y))`
and the previous expression is expanded to
`a = 2 * ((3 + b) < (8) ? -(3 + b) : (8))`.

Another example, if the file `foo.h` contains the header:
```c
int foo(int);
```

and if the file `main.c` is:
```c
#include "foo.h"

int main(void){
   foo(2);
   return 0;
}
```

then the preprocessor send to the compiler the file:
```c
int foo(int);

int main(void){
   foo(2);
   return 0;
}
```

## Error in preprocessor

You can force a error in preprocessing as:
```c
#error "A test"
```

## Pragmas

Standard pragmas:
```c
#pragma STDC FENV_ACCESS arg 	// (1) 	(since C99)
#pragma STDC FP_CONTRACT arg 	// (2) 	(since C99)
#pragma STDC CX_LIMITED_RANGE arg 	// (3) 	(since C99)
```

where arg is either **ON** or **OFF** or **DEFAULT**.
1. If set to **ON**, informs the compiler that the program will access or modify
floating-point environment, which means that optimizations that could subvert
flag tests and mode changes (e.g., global common subexpression elimination,
code motion, and constant folding) are prohibited. The default value is
implementation-defined, usually **OFF**.
1. Allows contracting of floating-point expressions, that is optimizations
that omit rounding errors and floating-point exceptions that would be observed
if the expression was evaluated exactly as written. For example, allows the
implementation of `(x*y) + z` with a single fused multiply-add CPU instruction.
The default value is implementation-defined, usually **ON**.
1. Informs the compiler that multiplication, division, and absolute value of
complex numbers may use simplified mathematical formulas
`(x+iy)×(u+iv) = (xu-yv)+i(yu+xv)`,
`(x+iy)/(u+iv) = [(xu+yv)+i(yu-xv)]/(u^2+v^2)`, `and |x+iy| = √(x^2+y^2)`,
despite the possibility of intermediate overflow. In other words, the
programmer guarantees that the range of the values that will be passed to those
function is limited. The default value is **OFF**.

## Source code to diferent...

You can write a specific source code to different operational system.
```c
#if defined(__ANDROID_API__)
   /* android compatible source code. */
#elif defined(__linux__)
   /* linux compatible source code. */
#elif defined(_WIN32)
   /* windows compatible source code. */
#elif defined(__APPLE__)
   /* MAC OS compatible source code. */
#else
   #error "OS not supported!"
#endif
```

In the case of `__ANDROID_API__` is declared
you can write a specific source code to different version of android.

```c
#if __ANDROID_API__ >= 28
   /* Android Pie compatible source code. */
#elif __ANDROID_API__ >= 26
   /* Android Oreo compatible source code. */
#elif __ANDROID_API__ >= 24
   /* Android Nougat compatible source code. */
#elif __ANDROID_API__ >= 23
   /* Android Marshmallow compatible source code. */
#elif __ANDROID_API__ >= 19
   /* Android KitKat compatible source code. */
#else
   #error "Android not suported!"
#endif
```

You can write a specific source code to different version of ISO C.
```c
#if defined(__STDC_VERSION__)
   #if __STDC_VERSION__ >= 201710L
   /* C17 compatible source code. */
   #elif __STDC_VERSION__ >= 201112L
   /* C11 compatible source code. */
   #elif __STDC_VERSION__ >= 199901L
   /* C99 compatible source code. */
   #elif __STDC_VERSION__ >= 199409L
   /* C95 compatible source code. */
   #endif
#elif defined(__STDC__)
   /* C89 compatible source code. */
#else
   /* K&R C compatible source code. */
#endif /* __STDC_VERSION__ */
```
