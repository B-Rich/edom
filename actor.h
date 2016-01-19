#ifndef __ACTOR__
#define __ACTOR__

#include "sysdep.h"
#include "sprite.h"

enum facing
{
  LEFT, RIGHT, UP, DOWN
};

enum action
{
  IDLE, MOVE, ATTACK
};

struct anim_info
{
  int anchor_x, anchor_y;
  int left, right, up, down;
  int num_walk_frames;
  int speed;
  int treshold;
  int attack_left, attack_right, attack_up, attack_down;
  int num_attack_frames;
};

struct actor
{
  /* Coordinates on tile map */
  int16 x, y;

  /* Player movement vector */
  coord dx, dy;

  /* Which direction is the actor facing */
  enum facing dir;

  /* Actor action */
  enum action act;

  /* Animation information */
  struct anim_info anim_info;

  /* Animation idle counter */
  int counter;

  /* Actor sprite frame */
  int base_frame;
  int delta_frame;
  BOOL rev_anim;

  /* Actor sprite */
  SPRITE *spr;
};

void init_actor(struct actor *a, const char *fn, int w, int h, const struct anim_info *info);
void set_dir_actor(struct actor *a, enum facing dir);
void animate_walk_actor(struct actor *a);
void move_actor(struct actor *a, enum facing dir);
void animate_move_actor(struct actor *a);
void set_attack_actor(struct actor *a, enum facing dir);
void animate_attack_actor(struct actor *a);
void draw_actor(struct actor *a);

#endif
