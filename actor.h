#ifndef __ACTOR__
#define __ACTOR__

#include "sysdep.h"
#include "sprite.h"

enum facing
{
  LEFT, RIGHT, UP, DOWN
};

struct anim_info
{
  int left, right, up, down;
  int speed;
  int treshold;
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

  /* Animation information */
  struct anim_info anim_info;

  /* Animation idle counter */
  int counter;

  /* Actor sprite frame */
  int base_frame;
  int delta_frame;

  /* Actor sprite */
  SPRITE *spr;
};

void init_actor(struct actor *a, const char *fn, int w, int h, const struct anim_info *info);
void set_dir_actor(struct actor *a, enum facing dir);
void move_actor(struct actor *a, byte dx, byte dy);
void animate_actor(struct actor *a);
void draw_actor(struct actor *a);

#endif
