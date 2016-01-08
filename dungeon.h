/*                               -*- Mode: C -*- 
 * dungeon.h -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Thomas Biskup
 * Created On      : Sun Dec 29 21:49:27 1996
 * Last Modified By: Thomas Biskup
 * Last Modified On: Thu Jan  9 20:46:20 1997
 * Update Count    : 44
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

#ifndef __DUNGEON__

#define __DUNGEON__

/*
 * Global includes.
 */

#include "sysdep.h"



/*
 * Directions for the dungeon.
 */

enum direction
{
  N, W, S, E, NW, SW, NE, SE, MAX_DIRECTION
};



/*
 * Tiles for the dungeon.
 */

#define NO_DOOR     -1
#define OPEN_DOOR   '/'
#define CLOSED_DOOR '+'
#define LOCKED_DOOR '\\'
#define ROCK        '#'
#define FLOOR       '.'
#define STAIR_DOWN  '>'
#define STAIR_UP    '<'

/*
 * Graphical tiles for map
 */

#define TILE_WIDTH   32
#define TILE_HEIGHT  32

#define TILE_UNKNOWN 1
#define TILE_FLOOR   0
#define TILE_ROCK    3
#define TILE_WALL    2
#define NUM_TILES    4

/*
 * Global variables.
 */

/* The current dungeon level. */
extern byte dl;



/*
 * Global functions.
 */

int room_width(coord, coord);
int room_height(coord, coord);

BOOL is_open(coord, coord);
BOOL might_be_open(coord, coord);
BOOL is_known(coord, coord);

char tile_at(coord, coord);

void init_dungeon(void);
void build_map(void);
void print_map(void);
void know(coord, coord);
void know_section(coord, coord);
void get_current_section(coord, coord, coord *, coord *);
void get_current_section_coordinates(coord, coord, coord *, coord *);
void paint_map(void);
void map_cursor(coord, coord);
void print_tile(coord, coord);
void print_tile_at_position(coord, coord);
void change_door(coord, coord, byte);
void set_knowledge(coord, coord, byte);
void draw_dungeon(void);

#endif





