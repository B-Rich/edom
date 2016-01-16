/*                               -*- Mode: C -*- 
 * sysdep.h -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Thomas Biskup
 * Created On      : Sun Dec 29 21:52:36 1996
 * Last Modified By: Thomas Biskup
 * Last Modified On: Thu Jan  9 21:01:09 1997
 * Update Count    : 42
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

#ifndef __SYSDEP__

#define __SYSDEP__

/*
 * Includes.
 */

#include "config.h"


/*
 * Standard types.
 */

typedef signed char    byte;
typedef unsigned char  ubyte;
typedef short          int16;
typedef unsigned short uint16;
typedef long           int32;
typedef unsigned long  uint32;



/*
 * Special types.
 */

typedef byte           BOOL;
typedef unsigned int   rand_type;

/* Guess the size for coordinate variables. */
#if (MAP_W > 127) || (MAP_H > 127)
typedef int16          coord;
#else
typedef byte           coord;
#endif

/*
 * Special constants.
 */

#ifndef TRUE
# define TRUE  ((BOOL) (1 > 0))
#endif

#ifndef FALSE
# define FALSE ((BOOL) (0 > 1))
#endif



/*
 * Global functions.
 */

byte rand_byte(byte);
uint16 rand_int(uint16);
uint32 rand_long(uint32);

void init_rand(void);

#endif
