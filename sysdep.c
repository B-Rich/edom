/*                               -*- Mode: C -*- 
 * sysdep.c -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Thomas Biskup
 * Created On      : Sun Dec 29 22:29:49 1996
 * Last Modified By: Thomas Biskup
 * Last Modified On: Thu Jan  9 22:20:44 1997
 * Update Count    : 36
 * Status          : Unknown, Use with caution!
 *
 * (C) Copyright 1996, 1997 by Thomas Biskup.
 * All Rights Reserved.
 *
 * This software may be distributed only for educational, research and
 * other non-proft purposes provided that this copyright notice is left
 * intact.  If you derive a new game from these sources you also are
 * required to give credit to Thomas Biskup for creating them in the first
 * place.  These sources must not be distributed for any fees in excess of
 * $3 (as of January, 1997).
 */

#include "config.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"


/*
 * Prototypes.
 */

void initialize_colors(void);



/*
 * Initialize the random number generator.
 */

void init_rand(void)
{
  srandom(time(NULL));
}



/*
 * Return a random 8-bit number.
 */

byte rand_byte(byte max)
{
  return (byte) (random() % max);
}


/*
 * Return a random 16-bit number.
 */

uint16 rand_int(uint16 max)
{
  return (uint16) (random() % max);
}


/*
 * Return a random 32-bit number.
 */

uint32 rand_long(uint32 max)
{
  return (uint32) (random() % max);
}




