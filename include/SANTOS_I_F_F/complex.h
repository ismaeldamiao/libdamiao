#ifndef SANTOS_I_F_F_COMPLEX_H
#define SANTOS_I_F_F_COMPLEX_H 1

/* C99 expands _Complex_I to a constant expression of type
   (const float _Complex), with the value of the imaginary unit.
   See ISO/IEC 9899:1999 7.3.1 2.
   I set to a (const double _Complex). */
#ifdef _Imaginary_I
# undef _Complex_I
const double _Complex _Complex_I = (double _Complex)_Imaginary_I;
#else
const double _Complex _Imaginary_I = (double _Complex)_Complex_I;
# undef _Complex_I
const double _Complex _Complex_I = (double _Complex)_Imaginary_I;
#endif

/* Some implementations of the C standards use functions in creal and cimag, but
   is best use simples operators (musl implemented like this). */
#ifdef creal
# undef creal
#endif
#define creal(z) ((double)(z)) // ISO/IEC 9899:1999 6.3.1.7 2

#ifdef cimag
# undef cimag
#endif
double _Complex __CIMAG; // ISO/IEC 9899:1999 6.2.5 13
#define cimag(z) (__CIMAG = (z), ((double*)&(__CIMAG))[1])

/* C99 not define CMPLX by standard. */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
# define CMPLX(x, y) ((x) + _Complex_I*(y))
#endif

/* Some non standard implementations. */
#include "./complex/atoc.c"    // Convert a string to _Complex double

#endif /* SANTOS_I_F_F_COMPLEX_H */
