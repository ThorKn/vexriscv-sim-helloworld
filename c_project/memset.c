/*
** Copyright 2005, Michael Noisternig. All rights reserved.
** Copyright 2001, Travis Geiselbrecht. All rights reserved.
** Distributed under the terms of the NewOS License.
*/
/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <string.h>
#include <sys/types.h>

// void *
// memset(void *s, int c, size_t count)
// {
// 	char *xs = (char *) s;
// 	// size_t len = (-(size_t)s) & (sizeof(size_t)-1);
// 	// int cc = c & 0xff;
// 	// if ( count > len ) {
// 	// 	count -= len;
// 	// 	cc |= cc << 8;
// 	// 	cc |= cc << 16;
// 	// 	// write to non-aligned memory byte-wise
// 	// 	for ( ; len > 0; len-- )
// 	// 		*xs++ = c;
// 	// 	// write to aligned memory dword-wise
// 	// 	for ( len = count/sizeof(size_t); len > 0; len-- ) {
// 	// 		*((size_t *)xs) = cc;
// 	// 		xs += sizeof(size_t);
// 	// 	}
// 	// 	count &= sizeof(size_t)-1;
// 	// }
// 	// write remaining bytes
// 	for ( ; count > 0; count-- )
// 		*xs++ = (char) c;
// 	return s;
// }

void *
memset (void *dest, int val, size_t len)
{
  unsigned char *ptr = dest;
  while (len-- > 0)
    *ptr++ = (unsigned char) val;
  return dest;
}