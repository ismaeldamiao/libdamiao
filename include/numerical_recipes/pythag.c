/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 70
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#include <math.h>
/*******************************************************************************
Computes (a**2 + b**2)**1/2 without destructive underflow or overflow.
*******************************************************************************/
double pythag(double a, double b){
   double absa, absb, c;
   absa = fabs(a);
   absb = fabs(b);
   if(absa > absb){
      c = absb/absa;
      c = absa * sqrt(1.0 + c * c);
   }else{
      c = absa/absb;
      c = (absb == 0.0 ? 0.0 : absb * sqrt(1.0 + c * c));
   }
   return c;
}
