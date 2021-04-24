SANTOS, I.F.F. (Ismael Damião) recipes

This directory contains some functions implemented or developed by
SANTOS, I.F.F. (Ismael Damião), the author.

The functions developed by Ismael Damião are licenced by MIT LICENSE and
contains a copy of license in source files. The other functions
are found on the internet without license.

See [LICENSE](LICENSE).

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
