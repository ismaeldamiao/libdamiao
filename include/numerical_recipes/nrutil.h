/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#ifndef _NR_UTILS_H_
#define _NR_UTILS_H_

#define SIGN(a, b) copysign(a, b)

/* *****************************************************************************
   Chapter 2: Solution of Linear Equations
***************************************************************************** */
double pythag(double, double);

/* *****************************************************************************
   Chapter 7: Random Numbers
***************************************************************************** */
void psdes(unsigned long*,unsigned long*);
double ran0(long int*);
double ran1(long int*);
double ran2(long int*);
double ran3(long int*);
double ran4(long int*);

/* *****************************************************************************
   Chapter 11: Eigensystems
***************************************************************************** */
void tred2(double**,int,double*,double*);
int tqli(double*,double*,int,double**);

#endif /* _NR_UTILS_H_ */
