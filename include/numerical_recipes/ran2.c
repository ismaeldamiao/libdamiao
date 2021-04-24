/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 282
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#define IM1 2147483563L
#define IM2 2147483399L
#define AM (1.0/IM1)
#define IMM1 (IM1-1L)
#define IA1 40014L
#define IA2 40692L
#define IQ1 53668L
#define IQ2 52774L
#define IR1 12211L
#define IR2 3791L
#define NTAB 32L
#define NDIV (1L+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
/* *****************************************************************************
Long period (> 2 × 10 18 ) random number generator of L’Ecuyer with Bays-Durham
shuffle and added safeguards. Returns a uniform random deviate between 0.0 and
1.0 (exclusive of the endpoint values). Call with idum a negative integer to
initialize; thereafter, do not alter idum between successive deviates in a
sequence. RNMX should approximate the largest floating value that is less than
1.
***************************************************************************** */
double ran2(long int *idum){
   static long int idum2=123456789L, iy=0L, iv[NTAB];
   long int k;
   int j;
   double temp;
   if(*idum <= 0L){ // Initialize.
      if(-(*idum) < 1L) *idum=1L; // Be sure to prevent idum = 0.
      else *idum = -(*idum);
      idum2 = (*idum);
      for(j = NTAB+7L; j >= 0L; j--){ // Load the shuffle table (after 8 warm-ups).
         k = (*idum) / IQ1;
         *idum = IA1 * (*idum - k * IQ1) - k * IR1;
         if(*idum < 0L) *idum += IM1;
         if(j < NTAB) iv[j] = *idum;
      }
      iy = iv[0];
   }
   k = (*idum) / IQ1; // Start here when not initializing.
   *idum = IA1 * (*idum - k*IQ1) - k*IR1; // Compute idum=(IA1*idum) % IM1 without
   if(*idum < 0L) *idum += IM1; // overflows by Schrage’s method.
   k = idum2 / IQ2;
   idum2 = IA2 * (idum2-k * IQ2) - k*IR2; // Compute idum2=(IA2*idum) % IM2 likewise.
   if(idum2 < 0L) idum2 += IM2;
   j = iy/NDIV; // Will be in the range 0..NTAB-1.
   iy = iv[j] - idum2; // Here idum is shuffled, idum and idum2 are
   iv[j] = *idum; // combined to generate output.
   if(iy < 1L) iy += IMM1;
   if((temp=AM*(double)iy) > RNMX) return RNMX; // Because users don’t expect endpoint values.
   else return temp;
}
#undef IM1
#undef IM2
#undef AM
#undef IMM1
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX
/* *****************************************************************************
Period > 2e18
Relative (ran0) time execution = 2.0
ran2(&idum) \in [0, 1)
***************************************************************************** */
