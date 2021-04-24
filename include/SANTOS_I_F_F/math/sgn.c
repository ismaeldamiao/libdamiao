/* ***
   Compute the sign of a number.
   https://en.wikipedia.org/wiki/Sign_function
*** */
double sgn(double x){
   if(x > 0.0)      return  1.0;
   else if(x < 0.0) return -1.0;
   else             return  0.0;
}
