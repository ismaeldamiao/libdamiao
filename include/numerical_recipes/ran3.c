/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 283
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#include <stdlib.h> // Change to math.h in K&R C.
#define MBIG 1000000000L
#define MSEED 161803398L
#define MZ 0L
#define FAC (1.0/MBIG)
/* *****************************************************************************
According to Knuth, any large MBIG , and any smaller (but still large) MSEED
can be substituted for the above values.
********************************************************************************
Returns a uniform random deviate between 0.0 and 1.0. Set idum to any
negative value to initialize or reinitialize the sequence.
***************************************************************************** */
double ran3(long int *idum){
   static int inext, inextp;
   static long int ma[56]; // The value 56 (range ma[1..55]) is special and
   static int iff = 0; // should not be modified; see Knuth.
   long int mj, mk;
   int i, ii, k;

   if (*idum < 0L || iff == 0){ // Initialization.
      iff = 1;
      mj = labs(MSEED-labs(*idum)); // Initialize ma[55] using the seed idum and the
      mj %= MBIG; // large number MSEED.
      ma[55] = mj;
      mk = 1L;
      for(i = 1; i <= 54; i++){ // Now initialize the rest of the table,
         ii = (21*i) % 55; // in a slightly random order,
         ma[ii] = mk; // with numbers that are not especially random.
         mk = mj - mk;
         if(mk < MZ) mk += MBIG;
         mj = ma[ii];
      }
      for(k = 1; k <= 4; k++){ // We randomize them by “warming up the generator.”
         for(i = 1; i <= 55; i++){
            ma[i] -= ma[1+(i+30) % 55];
            if(ma[i] < MZ) ma[i] += MBIG;
         }
      }
      inext = 0; // Prepare indices for our first generated number.
      inextp = 31; // The constant 31 is special; see Knuth.
      *idum = 1L;
   }
   // Here is where we start, except on initialization.
   if(++inext == 56) inext = 1; // Increment inext and inextp, wrapping around
   if(++inextp == 56) inextp = 1; // 56 to 1.
   mj = ma[inext] - ma[inextp]; // Generate a new random number subtractively.
   if(mj < MZ) mj += MBIG; // Be sure that it is in range.
   ma[inext] = mj; // Store it,
   return mj*FAC; // and output the derived uniform deviate.
}
#undef MBIG
#undef MSEED
#undef MZ
#undef FAC
/* *****************************************************************************
Period \approx ?
Relative (ran0) time execution = 0.6
ran3(&idum) \in [0, 1]
***************************************************************************** */
