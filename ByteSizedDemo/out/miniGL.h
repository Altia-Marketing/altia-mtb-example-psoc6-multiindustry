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

#if !defined(MINIGL_H)
#define MINIGL_H

#include "miniGLBase.h"
#include "miniGLFunctions.h"

    /*
     * MINIGL_INT altiaSendEvent(MINIGL_CONST AltiaMiniGLFunction eventName,
     *      AltiaEventType eventValue):
     * -------------------------------------------------------------------------
     * Initiates the transmission of an event to the Altia interface. The
     * event's (animation) name is given by eventName.  NOTE:  eventName for
     * MiniGL is actually an enumerated data type (integer) instead of a NULL
     * terminated character string.  To convert an animation name into the
     * proper enumerated (integer) value, use the ALT_ANIM() macro.  For
     * example, to generate an event on the animation "1_card":
     *
     *     altiaSendEvent(ALT_ANIM(1_card), 2);
     *
     * The event's value is given by eventValue.
     *
     * If altiaSendEvent() fails for any reason -1 is returned.  Otherwise, 0 is
     * returned.
     */
    extern MINIGL_INT altiaSendEvent(
        MINIGL_CONST AltiaMiniGLFunction index,
        MINIGL_CONST AltiaEventType eventValue
    );

    /*
     * MINIGL_INT altiaSendText(MINIGL_CONST AltiaMiniGLFunction eventName,
     *      MINIGL_CONST MINIGL_CHAR * text):
     * -------------------------------------------------------------------------
     * Initiates the transmission of a text string event to an Altia interface.
     * The event's (animation) name is given by eventName.  NOTE:  eventName for
     * MiniGL is actually an enumerated data type (integer) instead of a NULL
     * terminated character string.  To convert an animation into the proper
     * enumerated (integer) value, use the ALT_ANIM() macro.  For example, to
     * generate an event on the animation "1_text":
     *
     *     altiaSendText(ALT_ANIM(1_text), "MiniGL");
     *
     * Altia text output objects (text I/O's) accept strings in this manner and
     * display them in the selected font style on the screen. NOTE: the text
     * string must be NULL terminated.
     *
     * If altiaSendText() fails for any reason -1 is returned.  Otherwise, 0 is
     * returned.
     */
    extern MINIGL_INT altiaSendText(
        MINIGL_CONST AltiaMiniGLFunction index,
        MINIGL_CONST MINIGL_CHAR * string
    );

    /*
     * MINIGL_INT altiaFlushOutput(void):
     * -------------------------------------------------------------------------
     * altiaFlushOutput flushes the outgoing event cache and requests the
     * Altia interface to update its display graphics as needed.
     *
     * If altiaFlushOutput() fails for any reason -1 is returned.  Otherwise, 0
     * is returned.
     */
    extern MINIGL_INT altiaFlushOutput(
        void
    );

    /*
     * MINIGL_BOOLEAN altiaIsFlushComplete(MINIGL_UINT32 * steps);
     * -------------------------------------------------------------------------
     * When the tasking feature is enabled, this function is used to check if
     * altiaFlushOutput() has completed.  The altiaFlushOutput() function
     * returns -1 when the tasking feature preempts it.
     *
     * altiaIsFlushComplete() returns MINIGL_TRUE if altiaFlushOutput() is
     * finished.  Otherwise, MINIGL_FALSE is returned.  Optionally, this
     * function will return the number of steps processed.  A step is considered
     * a whole drawing operation such as a rectangle, raster, stencil, text I/O,
     * snapshot (raster), or drawing area object.
     *
     * If the tasking feature is disabled this function always returns
     * MINIGL_TRUE.
     */
    extern MINIGL_BOOLEAN altiaIsFlushComplete(
        MINIGL_UINT32 * steps
    );

    /*
     * MINIGL_INT altiaNextEvent(AltiaMiniGLFunction * eventName,
     *      AltiaEventType * eventValue):
     * -------------------------------------------------------------------------
     * Get the next available event that was routed to the client application
     * by an Altia miniGL interface.  This function "blocks" until an event is
     * available.  The only events that are routed are those that have been
     * previously selected by calling altiaSelectEvent() or
     * altiaSelectAllEvents().
     *
     * The event's (animation) name is given by eventName and is passed as a
     * pointer.  Similarly, the event's value, eventValue, is also passed as a
     * pointer.  Upon a successful return miniGL will populate eventName and
     * eventValue with relevant data. NOTE:  eventName for miniGL is actually
     * an enumerated data type (integer) instead of a NULL terminated character
     * string.  To convert an animation name into the proper enumerated
     * (integer) value, use the ALT_ANIM() macro provided by miniGLFunctions.h.
     *
     * If altiaNextEvent() fails for any reason -1 is returned.
     * Otherwise, 0 is returned.
     */
    extern MINIGL_INT altiaNextEvent(
        AltiaMiniGLFunction * eventName, AltiaEventType * eventValue
    );

    /*
     * MINIGL_INT altiaPending(void):
     * -------------------------------------------------------------------------
     * This function is used to check for Altia miniGL interface events that
     * are waiting to be received.  The number of events available is returned
     * where a return of zero (0) indicates no events are available.  Events
     * are selected for receipt using altiaSelectEvent() or
     * altiaSelectAllEvents().
     *
     * Normally, a call to altiaPending() is made prior to an altiaNextEvent()
     * call to determine if there are any events to get.  This is especially
     * true if the program wants to avoid blocking in the altiaNextEvent()
     * call.  Instead, it may wish to do other processing and come back later
     * for another check.
     *
     * Zero (0) is returned if no events are pending.  A positive non-zero
     * value is returned if events are pending and the value reflects the
     * number of pending events.  Upon error, -1 is returned.
     */
    extern MINIGL_INT altiaPending(
        void
    );

    /*
     * MINIGL_INT altiaSelectEvent(MINIGL_CONST AltiaMiniGLFunction eventName):
     * -------------------------------------------------------------------------
     * This function is used to select specific events to be routed to the
     * application by an Altia miniGL interface. Events that are selected in
     * this way can be received by calling altiaNextEvent().   The eventName
     * parameter specifies the name of the event that the application now wishes
     * to receive.  This would be in addition to any other events that have been
     * selected for receipt with prior calls to altiaSelectEvent().  An
     * application may also select to receive events of all types by calling
     * altiaSelectAllEvents().  NOTE:  eventName for miniGL is actually an
     * enumerated data type (integer) instead of a NULL terminated character
     * string.  To convert an animation into the proper enumerated (integer)
     * value, use the ALT_ANIM() macro provided by miniGLFunctions.h.
     *
     * If altiaSelectEvent() fails for any reason -1 is returned.
     * Otherwise, 0 is returned.
     */
    extern MINIGL_INT altiaSelectEvent(
        MINIGL_CONST AltiaMiniGLFunction eventName
    );

    /*
     * MINIGL_INT altiaSelectAllEvents(void):
     * -------------------------------------------------------------------------
     * This function is used to select all events to be routed to the
     * application by an Altia miniGL interface. Events that are selected in
     * this way can be received by calling altiaNextEvent().
     *
     * It is not recommended that altiaSelectAllEvents() be used to short-cut
     * the specific selection of events with altiaSelectEvent().  Selecting to
     * receive all events may degrade the application program as well as the
     * Altia miniGL interface performance because many events generated by the
     * Altia miniGL interface may only be of interest to the Altia miniGL
     * interface itself.
     *
     * If altiaSelectAllEvents() fails for any reason -1 is returned.
     * Otherwise, 0 is returned.
     */
    extern MINIGL_INT altiaSelectAllEvents(
        void
    );

    /*
     * MINIGL_INT altiaPollEvent(MINIGL_CONST AltiaMiniGLFunction index,
     *      AltiaEventType * eventValue);
     * -------------------------------------------------------------------------
     * This function is used to retrieve the current state of an Altia miniGL
     * interface animation event.  Only Control animation event states may be
     * polled.
     *
     * If altiaPollEvent() fails for any reason -1 is returned.  Otherwise, 0
     * is returned.
     */
    extern MINIGL_INT altiaPollEvent(
        MINIGL_CONST AltiaMiniGLFunction index, AltiaEventType * eventValue
    );

    /*
     * AltiaMiniGLFunction altiaGetFunctionEnum(
     *      MINIGL_CONST MINIGL_UINT8 * funcName);
     * -------------------------------------------------------------------------
     * This function is used to retrieve the enumerated data type value of a
     * miniGL function based on the equivalent string.  This is only necessary
     * when the logic is decoupled from the HMI graphics code.
     *
     * altiaGetFunctionEnum() returns the AltiaMiniGLFunction enumerated data
     * type value.  If the incoming function name string cannot be found -1 is
     * returned.
     */
    extern AltiaMiniGLFunction altiaGetFunctionEnum(
        MINIGL_CONST MINIGL_UINT8 * funcName
    );

    /*
     * MINIGL_CONST MINIGL_UINT8 * altiaGetFunctionName(
     *      MINIGL_CONST AltiaMiniGLFunction func);
     * -------------------------------------------------------------------------
     * This function is used to retrieve the relevant function string based on
     * the incoming AltiaMiniGLFunction.  This is only necessary when the logic
     * is decoupled from the HMI graphics code.
     *
     * altiaGetFunctionName() returns the function name string based on the
     * incoming AltiaMiniGLFunction value.  If the incoming AltiaMiniGLFunction
     * is out of bounds NULL is returned.
     */
    extern MINIGL_CONST MINIGL_UINT8 * altiaGetFunctionName(
        MINIGL_CONST AltiaMiniGLFunction func
    );

    /*
     * void altiaInvalidateDirtyExtents(void):
     * -------------------------------------------------------------------------
     * This function is used to force a full-screen redraw on the next call
     * to altiaFlushOutput().  By calling this it invalidates the dirty extent
     * list and forces a single extent equivalent to the size of the
     * display/frame.
     */
    extern void altiaInvalidateDirtyExtents(
        void
    );



    /*
     * MINIGL_INT altiaGetStringPixelWidth(MINIGL_INT textIoAnimationId,
     *      MINIGL_CHAR * stringToAnalyze, MINIGL_CHAR * tmpStringBuffer,
     *      MINIGL_UINT16 tmpStringBufferLength,
     *      MINIGL_UINT maxTextIoPixelWidth, MINIGL_INT * stringPixelLength,
     *      MINIGL_INT * stringIndexLastCharBeforeSplitVisual,
     *      MINIGL_INT * stringIndexLastCharBeforeSplitLogical);
     * -------------------------------------------------------------------------
     * This function calculates the pixel width of a specified string for a
     * designated text IO object.  The text I/O object is specified via the
     * textIoAnimationId parameter. The stringToAnalyze parameter must point to
     * NULL-terminated string.  A temporary string buffer must be supplied when
     * this function is called to be used as a scratch buffer for internal
     * purposes. The scratch buffer is required to help minimize statically
     * allocated RAM since this function may seldom be used.
     *
     * If the function completes successfully, the stringPixelLength pointer is
     * stuffed with the calculated pixel length of stringToAnalyze, as viewed on
     * the display (visual).
     *
     * If the function completes successfully, and
     * stringIndexLastCharBeforeSplitVisual isn’t NULL, the
     * stringIndexLastCharBeforeSplitVisual pointer is stuffed with the last
     * character index of the string that will fit into the specified
     * maxTextIoPixelWidth. This value represents the string as viewed on the
     * display (visual) which could be shaped.
     *
     * If the function completes successfully, and
     * stringIndexLastCharBeforeSplitLogical isn’t NULL, the
     * stringIndexLastCharBeforeSplitLogical pointer is stuffed with the last
     * character index of the string that will fit into the specified
     * maxTextIoPixelWidth. This value represents the string as characterized
     * by the application (logical). Please understand that calculating this
     * can be expensive since the text shaper must be interrogated multiple
     * times. For this reason, stringIndexLastCharBeforeSplitLogical is
     * optional. If text shaping isn’t enabled this value is meaningless.
     *
     * altiaGetStringPixelWidth() returns the following:
     *
     *      0 == success
     *     -1 == invalid text IO object specified
     *     -2 == NULL pointer specified for a parameter
     *     -3 == maxTextIoPixelWidth <= 0
     *     -4 == tmpStringBufferLength < length of string pointed to by
     *           stringToAnalyze
     */
    extern MINIGL_INT altiaGetStringPixelWidth(
        MINIGL_INT textIoAnimationId, MINIGL_CHAR * stringToAnalyze,
        MINIGL_CHAR * tmpStringBuffer, MINIGL_UINT16 tmpStringBufferLength,
        MINIGL_UINT maxTextIoPixelWidth, MINIGL_INT * stringPixelLength,
        MINIGL_INT * stringIndexLastCharBeforeSplitVisual,
        MINIGL_INT * stringIndexLastCharBeforeSplitLogical
    );

#endif /* !defined(MINIGL_H) */
