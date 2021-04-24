#ifndef SANTOS_I_F_F_COMPLEX_H
#define SANTOS_I_F_F_COMPLEX_H 1

/* ***
   C99 expands _Complex_I to a constant expression of type
   (const float _Complex), with the value of the imaginary unit.
   See ISO/IEC 9899:1999 7.3.1 2.
   I expands to a (const double _Complex).
*** */
#undef _Complex_I

#ifdef __GNUC__
#define _Complex_I 1.0i
#else
#define _Complex_I ((double _Complex){0.0,1.0}) // ISO/IEC 9899:1999 6.2.5 13
#endif

#undef I // Prevent that I expands to _Imaginary_I
#define I _Complex_I

/* ***
   To prevent that use function in creal and cimag instead of declare as
   operator.
*** */
#ifdef creal
#undef creal
#endif
#define creal(z) ((double)(z)) // ISO/IEC 9899:1999 6.3.1.7 2

#ifdef cimag
#undef cimag
#endif
double _Complex _z_cimag_tmp; // ISO/IEC 9899:1999 6.2.5 13
#define cimag(z) (_z_cimag_tmp = (z), ((double*)&(_z_cimag_tmp))[1])

/* ***
   C99 not define CMPLX by standard.
   Prevent C11 use functions in CMPLX instead of declare as operator.
*** */
#ifdef CMPLX
#undef CMPLX
#endif
#define CMPLX(x, y) ((double _Complex){x,y}) // ISO/IEC 9899:1999 6.2.5 13

/* *****************************************************************************
   Implementations
***************************************************************************** */
#include "./complex/atoc.c"    /* Convert a string to _Complex double */

#endif /* SANTOS_I_F_F_COMPLEX_H */
