/*
 * MINEOS version 1.0 by Guy Masters, John Woodhouse, and Freeman Gilbert
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 ***************************************************************************
 *
 * Byte swap an array c of n of elements each one N bytes long. The swapped
 * array is stored in another array b, different from c.
 * A good compiler should unroll the inner loops. Letting the compiler do it
 * gives us portability.  Note that we might want to isolate the
 * cases N = 2, 4, 8 (and 16 for long double and perhaps long long)
 *
 ***************************************************************************
 */
#include <string.h>
#include "config.h"
#define SWAP2(a, b) { (a) ^= (b); (b) ^= (a); (a) ^= (b); }

void
F77_FUNC(swap,SWAP)(char *c, char *b, int *N, int *n)
{
  int i, j;
  memcpy((void *)b, (void *)c,(*n)*(*N));
  for (i = 0; i < (*n)*(*N); i += *N)
    for (j = 0; j < *N/2; j ++)
      SWAP2(b[i + j], b[i + *N - j - 1]);
}

/*
 * Byte swap in place an array b of n of elements each one N bytes long.
 * A good compiler should unroll the inner loops. Letting the compiler do it
 * gives us portability.  Note that we might want to isolate the
 * cases N = 2, 4, 8 (and 16 for long double and perhaps long long)
 *
 */
void
F77_FUNC(swap1,SWAP1)(unsigned char *b, int *N, int *n)
{
  int i, j;
  for (i = 0; i < (*n)*(*N); i += *N)
    for (j = 0; j < *N/2; j ++)
      SWAP2(b[i + j], b[i + *N - j - 1]);
}
