/*****************************************************************************/
/* setjmp.h   v4.32                                                         */
/* Copyright (c) 1993-2002 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _SETJMP
#define _SETJMP

#include <linkage.h>

#ifdef __cplusplus
extern "C" namespace std {
#endif

#define setjmp(x) _setjmp(x)

#if defined(_TMS320C6X) || 0
    typedef int jmp_buf[13];
#elif defined(__TMS470__)
    typedef int jmp_buf[10];
#elif defined(__TMS320C55X__)
    typedef long jmp_buf[7];
#else
#warn "This header only intended for use with C6x, C54x, C55x, and Arm."
    typedef int jmp_buf[13];
#endif

_CODE_ACCESS int  _setjmp(jmp_buf env); 
_CODE_ACCESS void longjmp(jmp_buf env, int val);

#ifdef __cplusplus
} /* extern "C" namespace std */

#ifndef _CPP_STYLE_HEADER
using std::jmp_buf;
using std::_setjmp;
using std::longjmp;
#endif /* _CPP_STYLE_HEADER */

#endif /* __cplusplus */

#else

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::jmp_buf;
using std::_setjmp;
using std::longjmp;
#endif /* _CPP_STYLE_HEADER */

#endif /* __cplusplus */

#endif /* _SETJMP */
