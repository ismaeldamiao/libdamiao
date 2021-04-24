## What a macros?

Macros are instructions to preprocessor.
Macros change your code before and the compiler compile the changed code.

For example, if the macro `#define MAX(x, y) x < y ? -x : y` is called
by `a = 2 * MAX(3 + b, 8)` then it exapands the expression to
`a = 2 * 3 + b ? -3 + b : 8` and 2 is multiplied by 3 instead the max. The
correct way of define the macro is `#define MAX(x, y) ((x) < (y) ? -(x) : (y))`
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
