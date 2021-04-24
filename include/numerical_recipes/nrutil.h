/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#ifndef _NR_UTILS_H_
#define _NR_UTILS_H_

#define SIGN(a, b) ((b) < 0.0 ? -fabs(a) : fabs(a))

/* *****************************************************************************
   Chapter 2: Solution of Linear Equations
***************************************************************************** */
double pythag(double, double);

#include "pythag.c"

/* *****************************************************************************
   Chapter 7: Random Numbers
***************************************************************************** */
void psdes(unsigned long*,unsigned long*);

double ran0(long int*);
double ran1(long int*);
double ran2(long int*);
double ran3(long int*);
double ran4(long int*);

#include "psdes.c"
#include "ran0.c"
#include "ran1.c"
#include "ran2.c"
#include "ran3.c"
#include "ran4.c"

/* *****************************************************************************
   Chapter 11: Eigensystems
***************************************************************************** */
void tred2(double**,int,double*,double*);
int tqli(double*,double*,int,double**);

#include "tred2.c"
#include "tqli.c"

#endif /* _NR_UTILS_H_ */
