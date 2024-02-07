/* Copyright (c) 2005-2024 Altia Acquisition Corporation dba Altia, Inc.
 * All Rights Reserved.
 *
 * NOTICE: All information contained herein is, and remains
 * the property of Altia, Inc. The intellectual and technical concepts
 * contained herein are proprietary to Altia, Inc. and may be covered by
 * U.S. and Foreign Patents, patents in process, and are protected by trade
 * secret or copyright law. Dissemination of this information or reproduction
 * of this material is strictly forbidden unless prior written permission is
 * obtained from Altia, Inc.
 *
 * ALTIA, INC. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
 * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL
 * ALTIA, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
 * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * @file  miniGLBase.h
 * @brief Primary miniGL base header file
 *          _ _   _                   _       _       _
 *     __ _| | |_(_) __ _   _ __ ___ (_)_ __ (_) __ _| |
 *    / _` | | __| |/ _` | | '_ ` _ \| | '_ \| |/ _` | |
 *   | (_| | | |_| | (_| | | | | | | | | | | | | (_| | |
 *    \__,_|_|\__|_|\__,_| |_| |_| |_|_|_| |_|_|\__, |_|
 *                                              |___/
 * This file is the primary miniGL for base header file for
 * ByteSizedDemo.dsn.
 * Generated with: miniGL engine and packer modules (13.2.1.13).
 * DO NOT MODIFY!
 */
#if !defined(MINIGLBASE_H)
#define MINIGLBASE_H

/*lint --e{9024} MISRA 2012 Rule 20.10 '##' operator used in 'MINIGL_TEXT' */
/*lint --e{9026} MISRA 2012 Directive 4.9 function-like macros utilized */

#define MINIGL_CONST const
#define MINIGL_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MINIGL_MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef signed char MINIGL_INT8;
typedef unsigned char MINIGL_UINT8;
typedef signed short MINIGL_INT16;
typedef unsigned short MINIGL_UINT16;
typedef signed long MINIGL_INT32;
typedef unsigned long MINIGL_UINT32;
typedef signed long long MINIGL_INT64;
typedef unsigned long long MINIGL_UINT64;

typedef signed short MINIGL_SHORT;
typedef unsigned short MINIGL_USHORT;
typedef signed short MINIGL_COORD;
typedef int MINIGL_INDEX;
typedef int MINIGL_FBINDEX;
typedef int MINIGL_BINDEX;
typedef unsigned char MINIGL_UBYTE;
typedef signed char MINIGL_BYTE;
typedef signed int MINIGL_INT;
typedef unsigned int MINIGL_UINT;
typedef MINIGL_UINT8 MINIGL_BOOLEAN;

#ifndef MINIGL_PACKER
typedef MINIGL_INT32 AltiaEventType;
#endif /* !MINIGL_PACKER */

typedef void * AltiaMiniGLDAOCallBackFunction;
typedef MINIGL_INT32 AltiaMiniGLFunction;


#define MINIGL_TEXT(x) (MINIGL_CHAR *) L ## x
typedef MINIGL_UINT16 MINIGL_CHAR;



#define MINIGL_TRUE  (MINIGL_BOOLEAN)0x01U
#define MINIGL_FALSE (MINIGL_BOOLEAN)0x00U

/* Fixed signed 32-bit fixed point functions (1.17.14) */
#define MINIGL_FSHIFT (14U)
#define MINIGL_TWICE_FSHIFT (MINIGL_FSHIFT * 2U)
#define MINIGL_FX_DIV_ONE ((MINIGL_INT32)1 << (MINIGL_INT32)MINIGL_TWICE_FSHIFT)

#define MINIGL_MULFX_WILL_NOT_OVERFLOW(x,y) \
    (((MINIGL_INT32)((x)*(y)) >= (MINIGL_INT32)-131071L) && \
    ((MINIGL_INT32)((x)*(y)) <= (MINIGL_INT32)131071L))

#define MINIGL_IS_TRANSFORMED(t) \
    (((MINIGL_INT32)16384L != (t).a00) || ((MINIGL_INT32)16384L != (t).a11))
#define MINIGL_IS_NOT_TRANSFORMED(t) \
    (((MINIGL_INT32)16384L == (t).a00) && ((MINIGL_INT32)16384L == (t).a11))

extern MINIGL_INT32 fxmultiply(MINIGL_INT32 x, MINIGL_INT32 y);
#define MINIGL_MULFX(x,y) fxmultiply(x,y)

extern MINIGL_INT32 fxdivide(MINIGL_INT32 x, MINIGL_INT32 y);
#define MINIGL_DIVFX(x,y) fxdivide(x,y)

#define MINIGL_FX_ONE \
    ((MINIGL_INT32)((MINIGL_UINT32)1U << MINIGL_FSHIFT))

#ifndef MINIGL_INLINE
#define MINIGL_INLINE inline
#endif /* !MINIGL_INLINE */

/******************************************************************************/
/*!
 @brief Inline function to convert integer value to fixed point value

 This inline function is called to convert a signed 32-bit integer value to a
 signed 1.17.14 fixed point value.

 @param[in]  x  Signed 32-bit integer value

 @returns Signed 1.17.14 fixed point value
 */
/******************************************************************************/
static MINIGL_INLINE MINIGL_INT32 MINIGL_I2FX(
    MINIGL_CONST MINIGL_INT32 x)
{
    MINIGL_UINT32 fx = (MINIGL_UINT32)(((MINIGL_UINT32)x) << MINIGL_FSHIFT);
    return (MINIGL_INT32)fx;
}

/******************************************************************************/
/*!
 @brief Inline function to convert fixed point value to integer value

 This inline function is called to convert a signed 1.17.14 fixed point value
 to a signed 32-bit integer value.

 @param[in]  x  Signed 1.17.14 fixed point value

 @returns Signed 32-bit integer value
 */
/******************************************************************************/
static MINIGL_INLINE MINIGL_INT32 MINIGL_FX2I(
    MINIGL_CONST MINIGL_INT32 x)
{
    MINIGL_UINT32 fx;
    fx = (MINIGL_UINT32)(((MINIGL_UINT32)x) >> MINIGL_FSHIFT);
    if(x < (MINIGL_INT32)0L)
    {
        MINIGL_CONST MINIGL_UINT32 hmask =
            (((MINIGL_UINT32)~0LU) >> (32U -
                MINIGL_FSHIFT)) << (32U - MINIGL_FSHIFT);
        MINIGL_CONST MINIGL_UINT32 lmask =
            ((MINIGL_UINT32)~0LU) >> (32U - MINIGL_FSHIFT);
        fx |= hmask;
        if((MINIGL_UINT32)0LU != ((MINIGL_UINT32)x & lmask))
        {
            fx++;
        }
    }
    return (MINIGL_INT32)fx;
}

/******************************************************************************/
/*!
 @brief Inline function to convert fixed point value to integer floor value

 This inline function is called to convert a signed 1.17.14 fixed point value
 to a signed 32-bit integer floor value.

 @param[in]  x  Signed 1.17.14 fixed point value

 @returns Signed 32-bit integer floor value
 */
/******************************************************************************/
static MINIGL_INLINE MINIGL_INT32 MINIGL_FLOOR_FX2I(
    MINIGL_CONST MINIGL_INT32 x)
{
    MINIGL_UINT32 fx;
    fx = (MINIGL_UINT32)(((MINIGL_UINT32)x) >> MINIGL_FSHIFT);
    if(x < (MINIGL_INT32)0L)
    {
        MINIGL_CONST MINIGL_UINT32 hmask =
            (((MINIGL_UINT32)~0LU) >> (32U -
                MINIGL_FSHIFT)) << (32U - MINIGL_FSHIFT);
        fx |= hmask;
    }
    return (MINIGL_INT32)fx;
}

/******************************************************************************/
/*!
 @brief Inline function to convert fixed point value to rounded integer value

 This inline function is called to convert a signed 1.17.14 fixed point value
 to a signed 32-bit rounded integer value.

 @param[in]  x  Signed 1.17.14 fixed point value

 @returns Signed 32-bit rounded integer value
 */
/******************************************************************************/
static MINIGL_INLINE MINIGL_INT32 MINIGL_ROUND_FX2I(
    MINIGL_CONST MINIGL_INT32 x)
{
    MINIGL_CONST MINIGL_UINT32 half =
        (MINIGL_UINT32)(1LU << (MINIGL_FSHIFT - 1U));
    MINIGL_INT32 fx;
    if(x >= (MINIGL_INT32)0L)
    {
        MINIGL_UINT32 ufx = (MINIGL_UINT32)x;
        ufx += half;
        ufx >>= MINIGL_FSHIFT;
        fx = (MINIGL_INT32)ufx;
    }
    else
    {
        MINIGL_CONST MINIGL_UINT32 one =
            (MINIGL_UINT32)(1LU << MINIGL_FSHIFT);
        fx = x;
        fx -= (MINIGL_INT32)half;
        fx /= (MINIGL_INT32)one;
    }
    return fx;
}

/* Configurable signed 16-bit fixed point macros (1.x.x) */
#define MINIGL_S16FX_ONE(s) \
    ((MINIGL_INT16)((MINIGL_UINT16)1U << (s)))
#define MINIGL_S16FX_HALF(s) \
    ((MINIGL_INT16)((MINIGL_UINT16)1U << ((s) - (MINIGL_UINT16)1U)))
#define MINIGL_S16FX_MASK(s) \
    ((MINIGL_UINT16)(((MINIGL_UINT16)~0U) >> (16U - (s))))

#define MINIGL_I2S16FX(x,s) \
    ((MINIGL_INT16)((MINIGL_UINT16)(((MINIGL_UINT16)(x)) << (s))))
#define MINIGL_S16FX2I(x,s) (((x) >= (MINIGL_INT16)0) ? \
    (MINIGL_INT16)((x) >> (s)) : (MINIGL_INT16)(((x) >> (s)) + \
    (((MINIGL_UINT16)0U == ((MINIGL_UINT16)x & MINIGL_S16FX_MASK(s))) ? \
    (MINIGL_INT16)0 : (MINIGL_INT16)1)))
#define MINIGL_FLOOR_S16FX2I(x,s) ((MINIGL_INT16)((x) >> (s)))
#define MINIGL_ROUND_S16FX2I(x,s) (((x) >= (MINIGL_INT16)0) ? \
    (MINIGL_INT16)((MINIGL_UINT16)((x) + MINIGL_S16FX_HALF(s)) >> (s)) : \
    (MINIGL_INT16)(((x) - MINIGL_S16FX_HALF(s)) / MINIGL_S16FX_ONE(s)))
#define MINIGL_S16FX2FX(x,s) \
    ((MINIGL_INT32)(((MINIGL_UINT32)(x)) << (MINIGL_FSHIFT - (s))))

#endif /* !defined(MINIGLBASE_H) */
