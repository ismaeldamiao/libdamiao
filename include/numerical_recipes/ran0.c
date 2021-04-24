/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 279
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#define IA 16807L
#define IM 2147483647L
#define AM (1.0/IM)
#define IQ 127773L
#define IR 2836L
#define MASK 123459876L
/* *****************************************************************************
“Minimal” random number generator of Park and Miller. Returns a uniform random
deviate between 0.0 and 1.0.
Set or reset idum to any integer value (except the unlikely value MASK )
to initialize the sequence; idum must not be altered between calls for
successive deviates in a sequence.
***************************************************************************** */
double ran0(long int *idum){
   long int k;
   double ans;

   *idum ^= MASK; // XORing with MASK allows use of zero and other
   k = (*idum)/IQ;  // simple bit patterns for idum.
   *idum = IA * (*idum - k*IQ) - IR*k; // Compute idum=(IA*idum) % IM without over
   if (*idum < 0) *idum += IM; // flows by Schrage’s method.
   ans = AM*(*idum); // Convert idum to a floating result.
   *idum ^= MASK; // Unmask before return.
   return ans;
}
#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef MASK
/* *****************************************************************************
Period \approx 2.1e9
Relative (ran0) time execution = 1.0
ran0(&idum) \in [0, 1]
***************************************************************************** */
