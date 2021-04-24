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

You can write a specified souce code to diferent version of ISO C.
```c
/* *****************************************************************************
   To compile differently for each version of ISO C
***************************************************************************** */
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

