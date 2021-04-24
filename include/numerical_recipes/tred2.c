/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 474~475
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#include <math.h>
/*******************************************************************************
Householder reduction of a real, symmetric matrix a[1..n][1..n]. 
On output, a is replaced by the orthogonal matrix Q effecting the
transformation. d[1..n] returns the diagonal elements of the tridiagonal matrix,
and e[1..n] the off-diagonal elements, with e[1]=0. Several statements, as noted
in comments, can be omitted if only eigenvalues are to be found, in which case a
contains no useful information on output. Otherwise they are to be included.
*******************************************************************************/
void tred2(double **a, int n, double *d, double *e){
   int l, k, j, i;
   double scale, hh, h, g, f;

   for(i = n; i >= 2; i--){
      l = i - 1;
      h = scale = 0.0;
      if(l > 1){
         for(k = 1; k <= l; k++)
         scale += fabs(a[i][k]);
         if(scale == 0.0) /* Skip transformation. */
         e[i] = a[i][l];
         else{
            for(k = 1; k <= l; k++){
               a[i][k] /= scale; /* Use scaled a's for transformation. */
               h += a[i][k] * a[i][k]; /* Form sigma in h. */
            }
            f = a[i][l];
            g = (f >= 0.0 ? -sqrt(h) : sqrt(h));
            e[i] = scale * g;
            h -= f*g; /* Now h is equation (11.2.4). */
            a[i][l] = f - g; /* Store u in the ith row of a. */
            f = 0.0;
            for(j = 1; j <= l; j++) {
               /* Next statement can be omitted if eigenvectors not wanted */
               a[j][i] = a[i][j]/h; /* Store u/H in ith column of a. */
               g = 0.0; /* Form an element of A.u in g. */
               for(k = 1; k <= j; k++)
               g += a[j][k] * a[i][k];
               for(k = j+1; k <= l; k++)
               g += a[k][j] * a[i][k];
               e[j]=g/h;/*Form element of p in temporarily unused element of e*/
               f += e[j] * a[i][j];
            }
            hh = f/(h+h); /* Form K, equation (11.2.11). */
            for(j = 1; j <= l; j++) { /* Form q and store in e overwriting p. */
               f=a[i][j];
               e[j] = g = e[j] - hh*f;
               for(k = 1; k <= j; k++) /* Reduce a, equation (11.2.13). */
               a[j][k] -= (f*e[k]+g*a[i][k]);
            }
         }
      }else
      e[i]=a[i][l];
      d[i]=h;
   }
   /* Next statement can be omitted if eigenvectors not wanted */
   d[1] = 0.0;
   e[1] = 0.0;
   /* Contents of this loop can be omitted if eigenvectors not
   wanted except for statement d[i]=a[i][i]; */
   for(i = 1; i <= n; i++){ /* Begin accumulation of transformation matrices. */
      l = i - 1;
      if(d[i]){ /* This block skipped when i=1. */
         for(j = 1; j <= l; j++){
            g = 0.0;
            for(k = 1; k <= l; k++) /* Use u and u/H stored in a to form P.Q. */
            g += a[i][k]*a[k][j];
            for(k = 1; k <= l; k++)
            a[k][j] -= g * a[k][i];
         }
      }
      d[i] = a[i][i]; /* This statement remains. */
      a[i][i]=1.0;/*Reset row and column of a to identity matrix for next iteration*/
      for(j = 1; j <= l; j++) a[j][i] = a[i][j] = 0.0;
   }
}
