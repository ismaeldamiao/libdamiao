/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 280
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#define IA 16807L
#define IM 2147483647L
#define AM (1.0/IM)
#define IQ 127773L
#define IR 2836L
#define NTAB 32L
#define NDIV (1L+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
/* *****************************************************************************
“Minimal” random number generator of Park and Miller with Bays-Durham shuffle
and added safeguards. Returns a uniform random deviate between 0.0 and 1.0
(exclusive of the endpoint values). Call with idum a negative integer to
initialize; thereafter, do not alter idum between successive deviates in a
sequence. RNMX should approximate the largest floating value that is less
than 1.
***************************************************************************** */
double ran1(long int *idum){
   static long int iy=0L, iv[NTAB];
   long int k;
   int j;
   double temp;
   if(*idum <= 0L || !iy){ /* Initialize. */
      if (-(*idum) < 1L) *idum = 1L; /* Be sure to prevent idum = 0. */
      else *idum = -(*idum);
      for(j = NTAB + 7L; j >= 0L; j--){ /* Load the shuffle table (after 8 warm-ups). */
         k = (*idum) / IQ;
         *idum = IA * (*idum - k * IQ) - IR * k;
         if(*idum < 0L) *idum += IM;
         if(j < NTAB) iv[j] = *idum;
      }
      iy = iv[0];
   }
   k = (*idum) / IQ; /* Start here when not initializing. */
   *idum = IA * (*idum - k * IQ) - IR * k; /* Compute idum=(IA*idum) % IM without */
   if(*idum < 0L) *idum += IM; /* overflows by Schrage’s method. */
   j = iy / NDIV; /* Will be in the range 0..NTAB-1. */
   iy = iv[j]; /* Output previously stored value and refill the shuffle table.*/
   iv[j] = *idum;
   if((temp=AM*(double)iy) > RNMX) return RNMX; /* Because users don’t expect endpoint values. */
   else return temp;
}
#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
/* *****************************************************************************
Period \approx 20e8
Relative (ran0) time execution = 1.3
ran1(&idum) \in [0, 1)
***************************************************************************** */
