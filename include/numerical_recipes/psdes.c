/* *****************************************************************************
"Numerical Recipes in C" (Cambridge Univ. Press)
The Art of Scientific Computing, 2nd Edition, 1992 p 302~303
by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P. Flannery
***************************************************************************** */
#define NITER 4
/* *****************************************************************************
“Pseudo-DES” hashing of the 64-bit word (lword,irword).
Both 32-bit arguments are re-turned hashed on all bits.
***************************************************************************** */
void psdes(unsigned long *lword, unsigned long *irword){
   unsigned long i, ia, ib, iswap, itmph = 0L, itmpl = 0L;
   static unsigned long c1[NITER] =
   {0xbaa96887L, 0x1e17d32cL, 0x03bcdc3cL, 0x0f33d1b2L};
   static unsigned long c2[NITER] =
   {0x4b0f3b58L, 0xe874f0c3L, 0x6955c5a6L, 0x55a7ca46L};

   for(i = 0; i < NITER; i++){
      /* Perform niter iterations of DES logic, using a simpler
      (non-cryptographic) nonlinear func-tion instead of DES’s. */
      ia = (iswap=(*irword)) ^ c1[i]; // The bit-rich constants c1 and (below)
      itmpl = ia & 0xffff; //c2 guarantee lots of nonlinear mixing
      itmph = ia >> 16;
      ib = itmpl*itmpl+ ~(itmph*itmph);
      *irword = (*lword) ^ (((ia = (ib >> 16) |
      ((ib & 0xffff) << 16)) ^ c2[i])+itmpl*itmph);
      *lword = iswap;
   }
}
#undef NITER
