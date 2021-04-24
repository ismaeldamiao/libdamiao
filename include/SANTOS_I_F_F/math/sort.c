#include <float.h>
/*
   Sort the components of array v (of order N) by crescent order.
*/
double *sort(int N, double *v){
   int i, j, k;
   double lower;

   for(i = 0; i < N; ++i){
      lower = DBL_MAX;
      for(j = i; j < N; ++j)
      lower = (lower < v[j] ? lower : v[k = j]);

      v[k] = v[i]; /* lower value location get v[i] */
      v[i] = lower; /* Actual location get lower value */
   }
   return v;
}
