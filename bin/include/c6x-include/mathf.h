/****************************************************************************/
/*  mathf.h          v4.32                                                 */
/*  Copyright (c) 1997-2002  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:35 CDT 2000 */
 
#ifndef __mathf__
#define __mathf__

#ifndef EDOM
   #define EDOM   1
#endif

#ifndef ERANGE
   #define ERANGE 2
#endif

#include <float.h>

#if (FLT_DIG == DBL_DIG) /* float == double */

#include <math.h>

#define sqrtf    sqrt
#define expf     exp
#define logf     log
#define log10f   log10
#define powf     pow
#define sinf     sin
#define cosf     cos
#define tanf     tan
#define asinf    asin
#define acosf    acos
#define atanf    atan
#define atan2f   atan2
#define sinhf    sinh
#define coshf    cosh
#define tanhf    tanh

#define ceilf    ceil
#define floorf   floor

#define fabsf    fabs

#define ldexpf   ldexp
#define frexpf   frexp
#define modff    modf
#define fmodf    fmod

#ifdef _TI_ENHANCED_MATH_H

#define HUGE_VALF FLT_MAX

#define rsqrtf   rsqrt
#define exp2f    exp2
#define exp10f   exp10
#define log2f    log2
#define powif    powi
#define cotf     cot
#define acotf    acot
#define acot2f   acot2
#define cothf    coth
#define asinhf   asinh
#define acoshf   acosh
#define atanhf   atanh
#define acothf   acoth
#define truncf   _trunc
#define roundf   _round

#endif

#else /* float != double */

#include <access.h>

__EXTERN float sqrtf (float x);
__EXTERN float expf  (float x);
__EXTERN float logf  (float x);
__EXTERN float log10f(float x);
__EXTERN float powf  (float x, float y);
__EXTERN float sinf  (float x);
__EXTERN float cosf  (float x);
__EXTERN float tanf  (float x);
__EXTERN float asinf (float x);
__EXTERN float acosf (float x);
__EXTERN float atanf (float x);
__EXTERN float atan2f(float y, float x);
__EXTERN float sinhf (float x);
__EXTERN float coshf (float x);
__EXTERN float tanhf (float x);

__INLINE float ceilf (float x);
__INLINE float floorf(float x);

__EXTERN float fabsf (float x);

__EXTERN float ldexpf(float x, int n);
__EXTERN float frexpf(float x, int *exp);
__EXTERN float modff (float x, float *ip);
__EXTERN float fmodf (float x, float y);

/* An inline version of fmodf that works for limited domain only */
/* See comments in implementation below */
static __inline float _FMODF(float x, float y);

/* these present in many linked images, so we'll tell you about them. */
__EXTERN float _roundf(float x); /* round-to-nearest */
__EXTERN float _truncf(float x); /* truncate towards 0 */

#ifdef _TI_ENHANCED_MATH_H
#if 0
/* ------------------------------------------------- */
/* Routines below are an addition to ANSI math.h     */
/* Some (noted with "9x" in comment) will become ANSI*/
/* once C9x is approved.                             */
/* ------------------------------------------------- */
#endif

#define HUGE_VALF FLT_MAX /* 9x */

__EXTERN float rsqrtf(float x); /*   == 1/sqrtf(x) but *MUCH* faster         */
__EXTERN float exp2f (float x); /*9x mathematically equiv to powf(2.0 ,x)    */
__EXTERN float exp10f(float x); /*   mathematically equiv to powf(10.0,x)    */
__EXTERN float log2f (float x); /*9x mathematically equiv to logf(x)/logf(2.)*/

__EXTERN float powif (float x, int i); /* equiv to powf(x,(float)i) */

__EXTERN float cotf  (float x);
__EXTERN float acotf (float x);
__EXTERN float acot2f(float x, float y);

__EXTERN float cothf (float x);

__EXTERN float asinhf(float x); /* 9x */
__EXTERN float acoshf(float x); /* 9x */
__EXTERN float atanhf(float x); /* 9x */
__EXTERN float acothf(float x);

#define roundf(x) _roundf(x) // 9x round-to-nearest   
#define truncf(x) _truncf(x) // 9x truncate towards 0 
#endif

#ifdef _INLINE
/****************************************************************************/
/*  Inline versions of floorf, ceilf, fmodf                                 */
/****************************************************************************/

static __inline float floorf(float x) 
{
   float y; 
   return (modff(x, &y) < 0 ? y - 1 : y);
}

static __inline float ceilf(float x)
{
   float y; 
   return (modff(x, &y) > 0 ? y + 1 : y);
}

/* 
   The implementation below does not work correctly for all cases.
   Consider the case of fmod(Big, 3), for any Big > 2**(MANT_DIG+2).
   The correct result is one of 0,1, or 2.
   But the implementation below will *always* return 0 
   because the quotient is only an approximation.
*/
static __inline float _FMODF(float x, float y)
{
   float d = fabsf(x); 
   if (d - fabsf(y) == d) return (0);
   modff(x/y, &d);  
   return (x - d * y);
}

#endif

#include <unaccess.h>

#endif /* float == double */

#endif /* __mathf__ */
