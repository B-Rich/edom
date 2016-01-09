#ifndef __ACTOR__
#define __ACTOR__

#include "sysdep.h"
#include "sprite.h"

#define ACTOR_ANIM_TRESHOLD 10

#define ACTOR_FRAME_DOWN  0
#define ACTOR_FRAME_LEFT  3
#define ACTOR_FRAME_RIGHT 6
#define ACTOR_FRAME_UP    9

struct actor
{
  /* Player movement vector */
  coord dx, dy;

  /* Coordinates on tile map */
  int16 x, y;

  /* Set while player is moving from one tile to another */
  BOOL is_moving;

  int counter;

  /* Actor sprite frame */
  int curr_base_frame;
  int curr_delta_frame;
  int curr_frame;

  /* Actor sprite */
  SPRITE *spr;
};

void init_actor(struct actor *a, const char *fn, int w, int h);
void move_actor(struct actor *a, byte dx, byte dy);
void animate_actor(struct actor *a);
void draw_actor(struct actor *a);

#endif
