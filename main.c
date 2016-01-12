/*                               -*- Mode: C -*- 
 * main.c -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Thomas Biskup
 * Created On      : Sun Dec 29 22:55:15 1996
 * Last Modified By: Thomas Biskup
 * Last Modified On: Thu Jan  9 21:25:59 1997
 * Update Count    : 61
 * Status          : Unknown, Use with caution!
 *
 * On the following times I worked on this game:
 *  12/29/96, 12/30/96 [9:45pm-1:30am, 10:35am-11:11am, 1:25pm-2:55pm]
 *                     [5:18pm-6:55pm]
 *  12/31/96           [1:25pm-3:16pm]
 *  01/06/97           [11:28am-11:55am, 10:37pm-10:56pm]
 *  01/08/97           [11:25pm-1:04am]
 *  09/01/97           [6:40pm-10:55pm]
 *
 * Total time so far: 959 minutes = 15 hours, 59 minutes
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

/*
 * Includes.
 */

#include <stdio.h>
#include "SDL.h"
#include "sprite.h"
#include "main.h"


static SDL_Surface *screen;

int screen_width = 640;
int screen_height = 480;

struct anim_info common_anim =
{
  3, 6, 9, 0,
  2,
  4
};

/*
 * Local prototypes.
 */

int init(void);

/*
 * Local functions.
 */


int init(void)
{
  /* Initlaize SDL with video and sound if possible */
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fprintf(stderr, "Fatal Error -- Unable to initialize SDL: %s\n", SDL_GetError());
    return 0;
  }

  /* Install exit function */
  atexit(SDL_Quit);

  /* Initialize screen, setup gfx mode */
  screen = SDL_SetVideoMode(screen_width, screen_height, 32,
                            SDL_HWSURFACE|SDL_DOUBLEBUF);
  if (screen == NULL) {
    fprintf(stderr, "Fatal Error -- Unable to set video mode: %s\n",
            SDL_GetError());
    return 0;
  }

  set_sprite_context(screen, screen_width, screen_height);

  return 1;
}

void flip(void)
{
  SDL_Flip(screen);
}

/*
 * The main function.
 */

int main(int argc, char **argv)
{
  int tile_base = 0;

  /* Print startup message. */
  printf("Current dungeon size: %ld.\n"
	 , (long int) sizeof(struct dungeon_complex));
  printf("Current monster size: %ld.\n"
	 , (long int) sizeof(struct monster_struct));
  printf("Current section size: %ld.\n"
	 , (long int) sizeof(struct section));
  printf("\n");
  
  if (argc > 1)
    tile_base = atoi(argv[1]);
  
  if (!init())
    return 1;

  stdprtstr("Setting up the game...");
  
  /* Initialize everything. */
  init_rand();
  init_player();
  init_monsters();
  init_dungeon(tile_base);
  init_io();
  
  /* Play the game. */
  play();

  /* Clean up. */
  clean_up_io();
  
  /* Be done. */
  return 0;
}




