#include <math.h>

#ifndef M_PI
   #define M_PI            3.14159265358979323846  /* pi */
#endif

/*
   Computes arctan(y/x) were x and y are orthogonal cartesian coordinates from
   plane with euclidean metric and y/x is the angle that the point (x, y) does
   with the x axis.
*/
double atan2(double x, double y){
   if(x > 0.0){
      return atan(y/x);
   }else if(x < 0.0){
      if(y >= 0.0) return atan(y/x) + M_PI;
      else return atan(y/x) - M_PI;
   }else{
      if(y > 0.0) return 0.5*M_PI;
      else if(y < 0.0) return -0.5*M_PI;
      else return NAN;
   }
}
