/* Copyright (c) 2021-2024 Altia Acquisition Corporation dba Altia, Inc.
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
 * @file  miniGL_software_render.h
 * @brief Primary miniGL driver header file
 *          _ _   _                   _       _       _
 *     __ _| | |_(_) __ _   _ __ ___ (_)_ __ (_) __ _| |
 *    / _` | | __| |/ _` | | '_ ` _ \| | '_ \| |/ _` | |
 *   | (_| | | |_| | (_| | | | | | | | | | | | | (_| | |
 *    \__,_|_|\__|_|\__,_| |_| |_| |_|_|_| |_|_|\__, |_|
 *                                              |___/
 * This file is the miniGL driver header file for the miniGL
 * software render target.  This should be included in the
 * application code using the Altia API.
 */

#ifndef MINIGL_SOFTWARE_RENDER_H
#define MINIGL_SOFTWARE_RENDER_H

#ifdef __cplusplus
extern "C" {
#endif


#ifndef MINIGL_UNICODE
#define MINIGL_UNICODE
#endif /* !MINIGL_UNICODE */


#ifndef MINIGL_INLINE
#define MINIGL_INLINE inline
#endif /* !MINIGL_INLINE */

#include "miniGL.h"
#include "miniGLATRio.h"

/**
 * miniGL software render target/pipeline error codes
 */
#define MINIGL_RUNTIME_FONT_ENGINE_ERROR        (0x00000001LU)
#define MINIGL_ENGINE_ERROR                     (0x00000002LU)
#define MINIGL_TARGET_REFLASH_ERROR             (0x00000003LU)

/**
 * miniGL software render target BSP Stimulus (touch screen) event
 */
typedef struct
{
    MINIGL_UINT8 pen;       /* Pen position: 0=up, 1=down */
    MINIGL_UINT16 x;        /* X location */
    MINIGL_UINT16 y;        /* Y location */
} BSP_STIMULUS_EVENT;

/**
 * miniGL software render target BSP clipping rectangle extent
 */
typedef struct
{
    MINIGL_UINT16 x0;       /* Left */
    MINIGL_UINT16 y0;       /* Top */
    MINIGL_UINT16 x1;       /* Right (w = x1 - x0) */
    MINIGL_UINT16 y1;       /* Bottom (h = y1 - y0) */
} BSP_CLIPPING_RECTANGLE;

/**
 * miniGL software render target externals
 */
extern void bsp_ErrorHandler(MINIGL_CONST MINIGL_UINT32 errorCode,
    MINIGL_CONST MINIGL_UINT32 majorCode, MINIGL_CONST MINIGL_UINT32 minorCode);
extern MINIGL_UINT8 * bsp_ReflashQueryString(
    MINIGL_CONST MINIGL_UINT16 * string);
extern MINIGL_UINT32 bsp_GetTime(void);
extern MINIGL_INT bsp_GetEvent(BSP_STIMULUS_EVENT * event,
    MINIGL_INT32 timeout);
extern MINIGL_BOOLEAN bsp_IsHardwareBlocked(void);
extern MINIGL_INT bsp_DriverFlushing(void);
extern MINIGL_INT bsp_DriverFlushed(MINIGL_CONST MINIGL_INT16 dirtyExtentCount,
    MINIGL_CONST BSP_CLIPPING_RECTANGLE * dirtyExtentList);
extern void * bsp_GetBackFrameBuffer(void);

extern MINIGL_INT altiaInitDriver(void);
extern MINIGL_INT altiaDeinitDriver(void);
extern MINIGL_BOOLEAN altiaIsHardwareBlocked(void);


#ifdef __cplusplus
}
#endif

#endif /* !MINIGL_SOFTWARE_RENDER_H */
