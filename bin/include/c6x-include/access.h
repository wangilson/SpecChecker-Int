/****************************************************************************/
/*  access.h         v4.32                                                 */
/*  Copyright (c) 1997-2002  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:56:21 CDT 2000 */
 
#ifndef __EXTERN

   #undef __EXTERN
   #undef __INLINE
   #undef __STATIC

   #if defined(Generate_Sources)
      #undef _CODE_ACCESS
      #undef _DATA_ACCESS

      #if defined(_TMS320C6x) /* leave _CODE_ACCESS, _DATA_ACCESS in files */

         #define __STATIC static _DATA_ACCESS

      #else /* remove _CODE_ACCESS and _DATA_ACCESS from generated files */
         #define _CODE_ACCESS
         #define _DATA_ACCESS
         #define __STATIC static
      #endif

   #elif defined(_TMS320C6X)
      #include <linkage.h>
      #ifdef __cplusplus
         #define __EXTERN extern "C" _CODE_ACCESS
      #else
         #define __EXTERN extern _CODE_ACCESS
      #endif
      #define __INLINE _IDECL
      #define __STATIC static _DATA_ACCESS

   #else
      #undef _CODE_ACCESS
      #undef _DATA_ACCESS

      #if defined(_FAR_RTS)
         #define __EXTERN far extern
         #define __STATIC static far
         #define _CODE_ACCESS far
         #define _DATA_ACCESS far
 
      #else
         #ifdef __cplusplus
            #define __EXTERN extern "C"
         #else
            #define __EXTERN extern
         #endif
         #define __STATIC static
         #define _CODE_ACCESS
         #define _DATA_ACCESS
      #endif

      #if defined(_INLINE)
         #define __INLINE static __inline
      #else
         #define __INLINE __EXTERN
      #endif
   #endif
#endif

