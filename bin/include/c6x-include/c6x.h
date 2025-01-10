/*****************************************************************************/
/*  C6X.H v4.32                                                             */
/*  Copyright (c) 1996-2002 Texas Instruments Incorporated                   */
/*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

unsigned _extu	  (unsigned, unsigned, unsigned);
int      _ext	  (int,      unsigned, unsigned);
unsigned _set	  (unsigned, unsigned, unsigned);
unsigned _clr	  (unsigned, unsigned, unsigned);
unsigned _extur	  (unsigned, int);
int      _extr	  (int,      int);
unsigned _setr	  (unsigned, int);
unsigned _clrr	  (unsigned, int);
int      _sadd	  (int,      int);
long     _lsadd	  (int,      long);
int	 _ssub	  (int,      int);
long	 _lssub	  (int,      long);
int      _sshl	  (int,      unsigned);
int	 _add2	  (int,      int);
int	 _sub2	  (int,      int);
unsigned _subc	  (unsigned, unsigned);
unsigned _lmbd	  (unsigned, unsigned);
int      _abs	  (int);
long     _labs	  (long);
int      _sat	  (long);
unsigned _norm	  (int);
unsigned _lnorm	  (long);
int	 _smpy	  (int,      int);
int	 _smpyhl  (int,      int);
int	 _smpylh  (int,      int);
int	 _smpyh	  (int,      int);
int	 _mpy	  (int,      int);
int	 _mpyus	  (unsigned, int);
int	 _mpysu	  (int,      unsigned);
unsigned _mpyu	  (unsigned, unsigned);
int	 _mpyhl	  (int,      int);
int	 _mpyhuls (unsigned, int);
int	 _mpyhslu (int,      unsigned);
unsigned _mpyhlu  (unsigned, unsigned);
int	 _mpylh	  (int,      int);
int	 _mpyluhs (unsigned, int);
int	 _mpylshu (int,      unsigned);
unsigned _mpylhu  (unsigned, unsigned);
int	 _mpyh	  (int,      int);
int	 _mpyhus  (unsigned, int);
int	 _mpyhsu  (int,      unsigned);
unsigned _mpyhu	  (unsigned, unsigned);

#ifdef _TMS320C6700
double   _mpyid   (int,      int);
int    	 _spint   (float);
int    	 _dpint   (double);
float  	 _rcpsp   (float);
double 	 _rcpdp   (double);
float  	 _rsqrsp  (float);
double 	 _rsqrdp  (double);
#endif

unsigned _hi(double);  /* return the hi 32 bits of a double as an int */
unsigned _lo(double);  /* return the lo 23 bits of a double as an int */
  
double 	 _itod(unsigned, unsigned);  /* Create a double from 2 ints */
float  	 _itof(unsigned);            /* Create a float from an int */
unsigned _ftoi(float);               /* Create an int from a float */

#ifdef _TMS320C6400
int      _add4      (int,      int);
int      _avg2      (int,      int);
unsigned _avgu4     (unsigned, unsigned);
int      _cmpeq2    (int,      int);
int      _cmpeq4    (int,      int);
int      _cmpgt2    (int,      int);
unsigned _cmpgtu4   (unsigned, unsigned);
int      _dotp2     (int,      int);
int      _dotpn2    (int,      int);
int      _dotpnrsu2 (int,      unsigned);
int      _dotprsu2  (int,      unsigned);
int      _dotpsu4   (int,      unsigned);
unsigned _dotpu4    (unsigned, unsigned);
int      _gmpy4     (int,      int);
long     _ldotp2    (int,      int);
int      _max2      (int,      int);
unsigned _maxu4     (unsigned, unsigned);
int      _min2      (int,      int);
unsigned _minu4     (unsigned, unsigned);
double 	 _mpy2      (int,      int);
double 	 _mpyhi     (int,      int);
int      _mpyhir    (int,      int);
double   _mpyli     (int,      int);
int      _mpylir    (int,      int);
double   _mpysu4    (int,      unsigned);
double   _mpyu4     (unsigned, unsigned);
unsigned _pack2     (unsigned, unsigned);
unsigned _packh2    (unsigned, unsigned);
unsigned _packh4    (unsigned, unsigned);
unsigned _packhl2   (unsigned, unsigned);
unsigned _packl4    (unsigned, unsigned);
unsigned _packlh2   (unsigned, unsigned);
unsigned _rotl      (unsigned, unsigned);
int      _sadd2     (int,      int);
unsigned _saddu4    (unsigned, unsigned);
int      _saddus2   (unsigned, int);
unsigned _shlmb     (unsigned, unsigned);
int      _shr2      (int,      unsigned);
unsigned _shrmb     (unsigned, unsigned);
unsigned _shru2     (unsigned, unsigned);
double   _smpy2     (int,      int);
int      _spack2    (int,      int);
unsigned _spacku4   (int,      int);
int      _sshvl     (int,      int);
int      _sshvr     (int,      int);
int      _sub4      (int,      int);
int      _subabs4   (int,      int);
     
int      _abs2      (int);
unsigned _bitc4     (unsigned);
unsigned _bitr      (unsigned);
unsigned _deal      (unsigned);
int      _mvd       (int);
unsigned _shfl      (unsigned);
unsigned _swap4     (unsigned);
unsigned _unpkhu4   (unsigned);
unsigned _unpklu4   (unsigned);
unsigned _xpnd2     (unsigned);
unsigned _xpnd4     (unsigned);
#endif

extern __cregister volatile unsigned int AMR;
extern __cregister volatile unsigned int CSR;
extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int ISR;
extern __cregister volatile unsigned int ICR;
extern __cregister volatile unsigned int IER;
extern __cregister volatile unsigned int ISTP;
extern __cregister volatile unsigned int IRP;
extern __cregister volatile unsigned int NRP;

#ifdef _TMS320C6400
extern __cregister volatile unsigned int GFPGFR;
#endif

#ifdef _TMS320C6700
extern __cregister volatile unsigned int FADCR;
extern __cregister volatile unsigned int FAUCR;
extern __cregister volatile unsigned int FMCR;
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/*****************************************************************************/
/* SAVE_AMR -                                                                */
/*     Define a local 'volatile unsigned int' variable in your interrupt     */
/*     routine.                                                              */
/*     When invoking this macro, pass that local variable to save the AMR.   */
/*                                                                           */
/*     If you interrupted an assembly coded routine that may be using        */
/*     circular addressing, and you interrupt into a C coded interrupt       */
/*     service routine, you need to set the AMR to 0 for the C code and save */
/*     off the AMR register, so that it will have the correct value upon     */
/*     leaving the C interrupt service routine and returning to the assembly */
/*     code.                                                                 */
/*                                                                           */
/*     Add this routine immediately after your local variable definitions    */
/*     and before the start of your C interrupt code.                        */
/*****************************************************************************/
#define SAVE_AMR(temp_AMR)                                                    \
        do {                                                                  \
            temp_AMR = AMR;                                                   \
            AMR = 0;                                                          \
        } while (0)

/*****************************************************************************/
/* RESTORE_AMR -                                                             */
/*    When invoking this macro, pass the same local variable that was passed */
/*    to the SAVE_AMR macro.  This macro will restore the AMR to the value   */
/*    it had when interrupted out of the hand assembly routine.              */
/*                                                                           */
/*    Add this macro immediately before exiting the C interrupt service      */
/*    routine.                                                               */ 
/*****************************************************************************/
#define RESTORE_AMR(temp_AMR)                                                 \
        do {                                                                  \
            AMR = temp_AMR;                                                   \
        } while (0)

/*****************************************************************************/
/* SAVE_SAT -                                                                */
/*     Define a local 'volatile unsigned int' variable in your interrupt     */
/*     routine.                                                              */
/*     When invoking this macro, pass that local variable to save the SAT    */
/*     bit.                                                                  */
/*                                                                           */
/*     If you interrupted a routine that was performing saturated arithmetic */
/*     and the interrupt service routine is also performing saturated        */
/*     arithmetic, then you must save and restore the SAT bit in your        */
/*     interrupt service routine.                                            */
/*                                                                           */
/*     Add this routine immediately after your local variable definitions    */
/*     and before the start of your C interrupt code.                        */
/*****************************************************************************/
#define SAVE_SAT(temp_SAT)                                                    \
        do {                                                                  \
            temp_SAT = _extu(CSR, 22, 31);                                    \
        } while (0)

/*****************************************************************************/
/* RESTORE_SAT -                                                             */
/*    When invoking this macro, pass the same local variable that was passed */
/*    to the SAVE_SAT macro.  This macro will restore the SAT bit to the     */
/*    value it had when your application was interrupted.                    */
/*                                                                           */
/*    Add this macro immediately before exiting the C interrupt service      */
/*    routine.                                                               */ 
/*****************************************************************************/
#define RESTORE_SAT(temp_SAT)                                                 \
        do {                                                                  \
            CSR      = _clr(CSR, 9, 9);                                       \
            temp_SAT = _sshl(temp_SAT, 31);                                   \
        } while (0)
