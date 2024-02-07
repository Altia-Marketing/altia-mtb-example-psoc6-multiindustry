/* Copyright (c) 2019-2024 Altia Acquisition Corporation dba Altia, Inc.
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

#if !defined(MINIGL_ATRIO_H)
#define MINIGL_ATRIO_H

#include <stddef.h>

/*lint --e{970} MISRA 2012 Directive 4.6 modifiers used outside of typedefs */

/******************************************************************************
 * Definitions
 *****************************************************************************/

#ifndef SEEK_SET
#define SEEK_SET            (0)
#endif /* !SEEK_SET */

#ifndef SEEK_CUR
#define SEEK_CUR            (1)
#endif /* !SEEK_CUR */

#ifndef SEEK_END
#define SEEK_END            (2)
#endif /* !SEEK_END */

#ifndef EOF
#define EOF                 (-1)
#endif /* !EOF */

#ifndef ATR_PROT_READ
#define ATR_PROT_READ       (0)
#endif /* !ATR_PROT_READ */

#ifndef ATR_MAP_SHARED
#define ATR_MAP_SHARED      (0)
#endif /* !ATR_MAP_SHARED */


/* MAX_ATR_STREAMS defines the maximum number of streams that can
** be opened simultaneously.
*/
#ifndef MAX_ATR_STREAMS
#define MAX_ATR_STREAMS     ( 4 )
#endif /* !MAX_ATR_STREAMS */


/******************************************************************************
 * Types
 *****************************************************************************/

typedef void ATR_FILE;


/******************************************************************************
 * Public API
 *****************************************************************************/

ATR_FILE * atr_fopen(const char * filename, const char * mode);
size_t atr_fread(void * buffer, size_t size, size_t count, ATR_FILE * stream);
int atr_fseek(ATR_FILE * stream, long offset, int origin);
void atr_rewind(ATR_FILE * stream);
int atr_fgetc(ATR_FILE * stream);
long atr_ftell(ATR_FILE * stream);
int atr_feof(ATR_FILE * stream);
int atr_fileno(ATR_FILE * stream);
int atr_fclose(ATR_FILE * stream);

void * atr_mmap(void * addr, size_t len, int prot, int flags, int fd, long off);
int atr_munmap(void * addr, size_t len);

#endif /* !defined(MINIGL_ATRIO_H) */
