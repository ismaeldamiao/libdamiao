#ifndef SANTOS_I_F_F_COMPLEX_H
#define SANTOS_I_F_F_COMPLEX_H 1

/* ***
   To prevent that _Complex_I expands to a float
*** */
#undef _Complex_I
#define _Complex_I 1.0i

/* ***
   To prevent that use function in creal and cimag
*** */
#ifndef creal
#define creal(z) ((double)(z))
#endif

/*#ifndef cimag // Bad implementation
#define cimag(z) ((double)(-I*((z)-creal(z))))
#endif*/

/* ***
   C99 not define CMPLX by standard
*** */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
#ifdef _Imaginary_I
#define CMPLX(x, y) ((double)(x) + _Imaginary_I*(double)(y))
#else
#define CMPLX(x, y) ((double)(x) + _Complex_I*(double)(y))
#endif
#endif /* __STDC_VERSION__ */

/* *****************************************************************************
   Implementations
***************************************************************************** */
#include "./complex/atoc.c"    /* Convert a string to _Complex double */

#endif /* SANTOS_I_F_F_COMPLEX_H */
