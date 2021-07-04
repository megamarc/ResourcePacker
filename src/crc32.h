/*-
 *  COPYRIGHT (C) 1986 Gary S. Brown.  You may use this program, or
 *  code or tables extracted from it, as desired without restriction.
 */

#ifndef _CRC32_H
#define _CRC32_H

#include <stddef.h>

unsigned int crc32(unsigned int crc, const void *buf, unsigned int size);

#endif
