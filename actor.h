#ifndef __ACTOR__
#define __ACTOR__

#include "sysdep.h"
#include "sprite.h"

#define ACTOR_ANIM_TRESHOLD 4
#define ACTOR_SPEED         2

#define ACTOR_FRAME_DOWN  0
#define ACTOR_FRAME_LEFT  3
#define ACTOR_FRAME_RIGHT 6
#define ACTOR_FRAME_UP    9

enum facing
{
  LEFT, RIGHT, UP, DOWN
};

struct actor
{
  /* Player movement vector */
  coord dx, dy;

  /* Coordinates on tile map */
  int16 x, y;

  /* Which direction is the actor facing */
  enum facing dir;

  /* Set while player is moving from one tile to another */
  BOOL is_moving;

  int counter;

  /* Actor sprite frame */
  int base_frame;
  int delta_frame;

  /* Actor sprite */
  SPRITE *spr;
};

void init_actor(struct actor *a, const char *fn, int w, int h);
void set_dir_actor(struct actor *a, enum facing dir);
void move_actor(struct actor *a, byte dx, byte dy);
void animate_actor(struct actor *a);
void draw_actor(struct actor *a);

#endif
