/* *****************************************************************************
   Read a list of N values in array v and computes the bin required to
   get "partitions" partitions in a histogram. Later write all possibles
   values in h[0][] and count and write in h[1][] the quatities
   of ocurrence of all values.
   *****************************************************************************
   E-mail: ismaellxd@gmail.com
   Site: https://ismaeldamiao.github.io/
   *****************************************************************************
   Copyright (C) SANTOS, I.F.F. (Ismael Damiao)

   Permission is hereby granted, free of charge, to any person obtaining a copy 
   of this software and associated documentation files (the “Software”), to 
   deal in the Software without restriction, including without limitation the 
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
   sell copies of the Software, and to permit persons to whom the Software is 
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in 
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
   IN THE SOFTWARE.
***************************************************************************** */
#include <float.h>   /* DBL_MAX */
#include <stdlib.h>

#ifndef MAX
   #define MAX(x, y) ((x) > (y) ? (x) : (y))
#endif
#ifndef MIN
   #define MIN(x, y) ((x) < (y) ? (x) : (y))
#endif

double **histogram(double *v, int N, int partitions){
   int i, j;
   double **h;
   double lower, higher, bin;

   lower = DBL_MAX;
   higher = -DBL_MAX;
   for(i = 0; i < N; ++i){
      lower = MIN(lower, v[i]);
      higher = MAX(higher, v[i]);
   }
   bin = (higher-lower)/partitions;

   h = (double**)malloc((size_t)((2) * sizeof(double*)));
   h[0] = (double*)malloc((size_t)((partitions) * sizeof(double)));
   h[1] = (double*)malloc((size_t)((partitions) * sizeof(double)));
   for(i = 0; i < partitions; ++i){
      h[0][i] = lower + (double)(i+1)*bin;
      h[1][i] = 0.0;
   }
   for(i = 0; i < N; ++i){
      for(j = 0; j < partitions; ++j){
         if(v[i] <= h[0][j]){
            ++h[1][j];
            break;
         }
      }
   }
   return h;
}
