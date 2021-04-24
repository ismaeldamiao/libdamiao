#include <complex.h>
/* ***
   Compute the sign of a complex number.
   https://en.wikipedia.org/wiki/Sign_function
*** */
_Complex double csgn(_Complex double z){
   if(creal(z) > 0.0){
                              return  1.0 + 0.0i;
   }else if(creal(z) < 0.0){
                              return -1.0 + 0.0i;
   }else{
      if(cimag(z) > 0.0)      return  1.0 + 0.0i;
      else if(cimag(z) < 0.0) return -1.0 + 0.0i;
      else                    return  0.0 + 0.0i;
   }
}
