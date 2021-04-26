/* This file is a collection of functions and subroutine for use in
   physics, mathematics and engineering.
   This is conformed to the ISO/IEC 9899:1999 (also called C99), but
   contains intructions to compile with some GNU extensions if __GNUC__ is
   defined. */
#ifndef SANTOS_I_F_F
#define SANTOS_I_F_F 1

// If possible, enable
#ifdef __GNUC__
# pragma GCC optimize ("O3") // O3 optimaization,
# pragma GCC diagnostic warning "-Wall" // all warning and
# pragma GCC diagnostic warning "-Wextra" // more warning.
/* To test portabilit i enable informes if i use GCC extentions. */
# pragma GCC diagnostic warning "-Wpedantic"
#endif
/* *****************************************************************************
   C standard libraries
***************************************************************************** */
#include <stdio.h>   /* Many functions for file input and output */
#include <stdlib.h>  /* Numeric conversion functions, memory allocation */
#include <math.h>    /* Many mathematical functions */
#include <complex.h> /* Many complex mathematical functions */
#include <float.h>   /* DBL_MAX */
#include <limits.h>  /* INT_MAX, INT_MIN */
#include <time.h>    /* Defines date- and time-handling functions */
#include <stdarg.h>  /* var-args */
/* If you see the file tgmath.h you can note that the specifc term based on the
   general term of a function is found using various tests. In a loop this is
   very inneficient. Therefore do not use this. */
#define _TGMATH_H 1
//#include <tgmath.h>

/* *****************************************************************************
   Numerical recipes in C
***************************************************************************** */
#include "./numerical_recipes/nrutil.h"

/* *****************************************************************************
   MUSL implementations
***************************************************************************** */


/* *****************************************************************************
   Libraries implemented (but not necessarily developed) by author
***************************************************************************** */
#include "./SANTOS_I_F_F/math.h"
#include "./SANTOS_I_F_F/complex.h"
#include "./SANTOS_I_F_F/other.h"

#endif /* SANTOS_I_F_F */
