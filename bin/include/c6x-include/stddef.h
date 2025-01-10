/*****************************************************************************/
/* stddef.h   v4.32                                                         */
/* Copyright (c) 1993-2002 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _STDDEF
#define _STDDEF

#ifdef __cplusplus
extern "C" namespace std {
#endif

#ifndef NULL
#define NULL 0
#endif

#ifdef _TMS320C2000
typedef long ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif

#ifndef _SIZE_T
#define _SIZE_T
#ifdef _TMS320C2000
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif
#endif

#ifndef __cplusplus
#ifndef _WCHAR_T
#define _WCHAR_T

#if defined(_TMS320C6X)
typedef unsigned char wchar_t;
#elif defined(__TMS470__)
typedef unsigned short wchar_t;
#else /* C2000, C54x, and C55x */
typedef unsigned int wchar_t;
#endif

#endif /* _WCHAR_T */
#endif /* ! __cplusplus */

#ifndef __TMS320C55X__
#define offsetof(_type, _ident) ((size_t)__intaddr__(&(((_type *)0)->_ident)))
#else
#define offsetof(_type, _ident) \
    (__intaddr__( ((char *) &((_type *)0)->_ident) - ((char *) 0) ))
#endif

#ifdef __cplusplus
} /* extern "C" namespace std */

#ifndef _CPP_STYLE_HEADER
using std::ptrdiff_t;
using std::size_t;
/*using std::wchar_t;*/
#endif

#endif  /* __cplusplus */

#else

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::ptrdiff_t;
using std::size_t;
/*using std::wchar_t;*/
#endif

#endif  /* __cplusplus */

#endif  /* _STDDEF */
