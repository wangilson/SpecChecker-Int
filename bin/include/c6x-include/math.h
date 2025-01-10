/****************************************************************************/
/*  math.h           v4.32                                                 */
/*  Copyright (c) 1997-2002  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:35 CDT 2000 */
 
#ifndef __math__
#define __math__

#ifndef EDOM
#define EDOM   1
#endif

#ifndef ERANGE
#define ERANGE 2
#endif

#include <float.h>
#define HUGE_VAL  DBL_MAX
#define HUGE_VALL LDBL_MAX

#include <access.h>

__EXTERN double sqrt (double x);
__EXTERN double exp  (double x);
__EXTERN double log  (double x);
__EXTERN double log10(double x);
__EXTERN double pow  (double x, double y);
__EXTERN double sin  (double x);
__EXTERN double cos  (double x);
__EXTERN double tan  (double x);
__EXTERN double asin (double x);
__EXTERN double acos (double x);
__EXTERN double atan (double x);
__EXTERN double atan2(double y, double x);
__EXTERN double sinh (double x);
__EXTERN double cosh (double x);
__EXTERN double tanh (double x);

__INLINE double ceil (double x);
__INLINE double floor(double x);

__EXTERN double fabs (double x);

__EXTERN double ldexp(double x, int n);
__EXTERN double frexp(double x, int *exp);
__EXTERN double modf (double x, double *ip);
__EXTERN double fmod (double x, double y);

/* An inline version of fmod that works for limited domain only */
/* See comments in implementation below */
static __inline double _FMOD(double x, double y);

/* these present in many linked images, so we'll tell you about them. */
__EXTERN double _round(double x); /* round-to-nearest */
__EXTERN double _trunc(double x); /* truncate towards 0 */

/* the ANSI-optional *f and *l routines */
#include <mathf.h>
#include <mathl.h>

#include <access.h>

#ifdef _TI_ENHANCED_MATH_H
#if 0
/* ------------------------------------------------- */
/* Routines below are an addition to ANSI math.h     */
/* Some (noted with "9x" in comment) will become ANSI*/
/* once C9x is approved.                             */
/* ------------------------------------------------- */
#endif

__EXTERN double rsqrt(double x); /*   == 1/sqrt(x) but *MUCH* faster         */
__EXTERN double exp2 (double x); /*9x mathematically equiv to pow(2.0 ,x)    */
__EXTERN double exp10(double x); /*   mathematically equiv to pow(10.0,x)    */
__EXTERN double log2 (double x); /*9x mathematically equiv to log(x)/log(2.0)*/

__EXTERN double powi(double x, int i); /* equiv to pow(x,(double)i) */

__EXTERN double cot  (double x);
__EXTERN double acot (double x);
__EXTERN double acot2(double x, double y);

__EXTERN double coth (double x);

__EXTERN double asinh(double x); /* 9x */
__EXTERN double acosh(double x); /* 9x */
__EXTERN double atanh(double x); /* 9x */
__EXTERN double acoth(double x);

#define round(x) _round(x) // 9x round-to-nearest   
#define trunc(x) _trunc(x) // 9x truncate towards 0 

#endif

#ifdef _INLINE
/****************************************************************************/
/*  Inline versions of floor, ceil, fmod                                    */
/****************************************************************************/

static __inline double floor(double x) 
{
   double y; 
   return (modf(x, &y) < 0 ? y - 1 : y);
}

static __inline double ceil(double x)
{
   double y; 
   return (modf(x, &y) > 0 ? y + 1 : y);
}

/* 
   The implementation below does not work correctly for all cases.
   Consider the case of fmod(Big, 3), for any Big > 2**(MANT_DIG+2).
   The correct result is one of 0,1, or 2.
   But the implementation below will *always* return 0 
   because the quotient is only an approximation.
*/
static __inline double _FMOD(double x, double y)
{
   double d = fabs(x); 
   if (d - fabs(y) == d) return (0);
   modf(x/y, &d);  
   return (x - d * y);
}

#endif

#include <unaccess.h>

#endif /* __math__ */

