/****************************************************************************/
/*  mathl.h          v4.32                                                 */
/*  Copyright (c) 1997-2002  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:36 CDT 2000 */
 
#ifndef __mathl__
#define __mathl__

#ifndef EDOM
   #define EDOM   1
#endif

#ifndef ERANGE
   #define ERANGE 2
#endif

#include <float.h>

#if (LDBL_DIG == DBL_DIG) /* long double == double*/

#include <math.h>

#define sqrtl    sqrt
#define expl     exp
#define logl     log
#define log10l   log10
#define powl     pow
#define sinl     sin
#define cosl     cos
#define tanl     tan
#define asinl    asin
#define acosl    acos
#define atanl    atan
#define atan2l   atan2
#define sinhl    sinh
#define coshl    cosh
#define tanhl    tanh

#define ceill    ceil
#define floorl   floor

#define fabsl    fabs

#define ldexpl   ldexp
#define frexpl   frexp
#define modfl    modf
#define fmodl    fmod

#ifdef _TI_ENHANCED_MATH_H

#define HUGE_VALL LDBL_MAX

#define rsqrtl   rsqrt
#define exp2l    exp2
#define exp10l   exp10
#define log2l    log2
#define powil    powi
#define cotl     cot
#define acotl    acot
#define acot2l   acot2
#define cothl    coth
#define asinhl   asinh
#define acoshl   acosh
#define atanhl   atanh
#define acothl   acoth
#define truncl   _trunc
#define roundl   _round

#endif

#else /* long double != double */

#include <access.h>

__EXTERN long double sqrtl (long double x);
__EXTERN long double expl  (long double x);
__EXTERN long double logl  (long double x);
__EXTERN long double log10l(long double x);
__EXTERN long double powl  (long double x, long double y);
__EXTERN long double sinl  (long double x);
__EXTERN long double cosl  (long double x);
__EXTERN long double tanl  (long double x);
__EXTERN long double asinl (long double x);
__EXTERN long double acosl (long double x);
__EXTERN long double atanl (long double x);
__EXTERN long double atan2l(long double y, long double x);
__EXTERN long double sinhl (long double x);
__EXTERN long double coshl (long double x);
__EXTERN long double tanhl (long double x);

__INLINE long double ceill (long double x);
__INLINE long double floorl(long double x);

__EXTERN long double fabsl (long double x);

__EXTERN long double ldexpl(long double x, int n);
__EXTERN long double frexpl(long double x, int *exp);
__EXTERN long double modfl (long double x, long double *ip);
__EXTERN long double fmodl (long double x, long double y);

/* An inline version of fmod that works for limited domain only */
/* See comments in implementation below */
static __inline long double _FMODL(long double x, long double y);

__EXTERN long double _roundl(long double x); /* round-to-nearest */
__EXTERN long double _truncl(long double x); /* truncate towards 0 */

#ifdef _TI_ENHANCED_MATH_H
#if 0
/* ------------------------------------------------- */
/* Routines below are an addition to ANSI math.h     */
/* Some (noted with "9x" in comment) will become ANSI*/
/* once C9x is approved.                             */
/* ------------------------------------------------- */
#endif

#define HUGE_VALL LDBL_MAX /* ## */

__EXTERN long double rsqrtl(long double x); /*   1/sqrtl(x) but *MUCH* faster*/
__EXTERN long double exp2l (long double x); /*9x math equiv to powl(2.0 ,x)  */
__EXTERN long double exp10l(long double x); /*   math equiv to powl(10.0,x)  */
__EXTERN long double log2l (long double x);/*9x math equiv to logl(x)/logl(2)*/

__EXTERN long double powil (long double x, int i); /* == powl(x,(long double)i)*/

__EXTERN long double cotl  (long double x);
__EXTERN long double acotl (long double x);
__EXTERN long double acot2l(long double x, long double y);

__EXTERN long double cothl (long double x);

__EXTERN long double asinhl(long double x); /* 9x */
__EXTERN long double acoshl(long double x); /* 9x */
__EXTERN long double atanhl(long double x); /* 9x */
__EXTERN long double acothl(long double x);

#define roundl(x) _roundl(x) /* 9x round-to-nearest   */
#define truncl(x) _truncl(x) /* 9x truncate towards 0 */

#endif


#ifdef _INLINE
/****************************************************************************/
/*  Inline versions of floorl, ceill, fmodl                                 */
/****************************************************************************/

static inline long double floorl(long double x) 
{
   long double y; 
   return (modfl(x, &y) < 0 ? y - 1 : y);
}

static inline long double ceill(long double x)
{
   long double y; 
   return (modfl(x, &y) > 0 ? y + 1 : y);
}

/* 
   The implementation below does not work correctly for all cases.
   Consider the case of fmod(Big, 3), for any Big > 2**(MANT_DIG+2).
   The correct result is one of 0,1, or 2.
   But the implementation below will *always* return 0 
   because the quotient is only an approximation.
*/
static inline long double _FMODL(long double x, long double y)
{
   long double d = fabsl(x); 
   if (d - fabsl(y) == d) return (0);
   modfl(x/y, &d);  
   return (x - d * y);
}

#endif

#include <unaccess.h>

#endif /* long double == double */

#endif /* __mathl__ */
