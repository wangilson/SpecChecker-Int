/*****************************************************************************/
/* stdarg.h   v4.32                                                         */
/* Copyright (c) 1993-2002 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _STDARG
#define _STDARG

#ifdef __cplusplus
namespace std
{
#endif
   typedef char *va_list;
#ifdef __cplusplus
}
#endif

/********************************************************************/
/* WARNING - va_arg will not work for "float" type, must use double */
/* ALSO NOTE THAT DOUBLES MUST BE DOUBLE WORD ALIGNED               */
/********************************************************************/
#define va_end(_ap)
  
#define va_start(_ap, _parmN) \
         (_ap = ((char *)&(_parmN)) + (sizeof(_parmN) < 4 ? 4 : sizeof(_parmN)))

#ifdef _BIG_ENDIAN
#define va_arg(_ap, _type)                                       \
	(__va_argref(_type) ? **(_type**)(_ap)++:                \
         ((sizeof(_type) == sizeof(double)                       \
             ? ((_ap = (char *)(((int)_ap + 7) & ~7)),           \
	        (_ap += 8), (*(_type *)(_ap - 8)))               \
             : ((_ap += 4), (*(_type *)(_ap - (sizeof(_type))))))))
#else
#define va_arg(_ap, _type)                                       \
	(__va_argref(_type) ? **(_type**)(_ap)++:                \
         ((sizeof(_type) == sizeof(double)                       \
             ? ((_ap = (char *)(((int)_ap + 7) & ~7)),           \
	        (_ap += 8), (*(_type *)(_ap - 8)))               \
             : ((_ap += 4), (*(_type *)(_ap - 4))))))
#endif

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::va_list;
#endif /* _CPP_STYLE_HEADER */

#endif /* __cplusplus */

#else

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::va_list;
#endif /* _CPP_STYLE_HEADER */

#endif /* __cplusplus */

#endif /* _STDARG */
