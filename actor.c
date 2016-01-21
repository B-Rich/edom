#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "main.h"

void init_actor(struct actor *a, const char *fn, int w, int h, const struct anim_info *info)
{
  a->spr = load_sprite(fn, w, h);
  if (a->spr == NULL)
  {
    printf("Fatal Error -- Unable to load sprite: %s\n", fn);
    exit(1);
  }

  a->act = IDLE;
  a->tx = 0;
  a->ty = 0;

  a->base_frame = 0;
  a->delta_frame = 0;
  a->rev_anim = FALSE;
  a->counter = 0;

  memcpy(&a->anim_info, info, sizeof(struct anim_info));
}

void set_dir_actor(struct actor *a, enum facing dir)
{
  a->counter = 0;
  a->dir = dir;
  a->delta_frame = 1;

  switch (dir)
  {
    case LEFT:
      a->base_frame = a->anim_info.left;
      break;

    case RIGHT:
      a->base_frame = a->anim_info.right;
      break;

    case UP:
      a->base_frame = a->anim_info.up;
      break;

    case DOWN:
      a->base_frame = a->anim_info.down;
      break;

    default:
      a->base_frame = 0;
      break;
  }
}

void animate_walk_actor(struct actor *a)
{
  if (++a->counter == a->anim_info.treshold)
  {
    if (!a->rev_anim)
    {
      if (++a->delta_frame > a->anim_info.num_walk_frames - 1)
      {
        a->delta_frame = a->anim_info.num_walk_frames - 1;
        a->rev_anim = TRUE;
      }
    }
    else
    {
      if (--a->delta_frame < 0)
      {
        a->delta_frame = 0;
        a->rev_anim = FALSE;
      }
    }

    a->counter = 0;
  }
}

void move_actor(struct actor *a, enum facing dir)
{
  switch(dir)
  {
    case DOWN:
      a->tx = 0;
      a->ty = 1;
      break;

    case LEFT:
      a->tx = -1;
      a->ty = 0;
      break;

    case RIGHT:
      a->tx = 1;
      a->ty = 0;
      break;

    case UP:
      a->tx = 0;
      a->ty = -1;
      break;
  }

  a->act = MOVE;
}

BOOL animate_move_actor(struct actor *a)
{
  BOOL is_done = FALSE;

  if (a->act == MOVE)
  {
    animate_walk_actor(a);

    if (a->tx)
    {
      a->x += a->tx * a->anim_info.speed;
      if ((a->x % TILE_WIDTH) == 0)
      {
        a->tx = 0;
        a->delta_frame = 1;
        a->act = IDLE;
        is_done = TRUE;
      }
    }

    if (a->ty)
    {
      a->y += a->ty * a->anim_info.speed;
      if ((a->y % TILE_HEIGHT) == 0)
      {
        a->ty = 0;
        a->delta_frame = 1;
        a->act = IDLE;
        is_done = TRUE;
      }
    }
  }

  return is_done;
}

void set_charge_actor(struct actor *a, struct actor *target, int tx, int ty)
{
  a->tx = tx;
  a->ty = ty;
  a->counter = 0;
  a->delta_frame = 0;
  a->act = CHARGE;
  face_target_actor(a, target);
}

BOOL animate_charge_actor(struct actor *a)
{
  BOOL is_done = FALSE;

  if (++a->counter >= a->anim_info.latency)
  {
    a->counter = 0;
    set_attack_actor(a);
    a->act = ATTACK;
    is_done = TRUE;
  }

  return is_done;
}

void set_attack_actor(struct actor *a)
{
  a->counter = 0;
  a->delta_frame = 0;
  a->act = ATTACK;

  switch (a->dir)
  {
    case LEFT:
      a->base_frame = a->anim_info.attack_left;
      break;

    case RIGHT:
      a->base_frame = a->anim_info.attack_right;
      break;

    case UP:
      a->base_frame = a->anim_info.attack_up;
      break;

    case DOWN:
      a->base_frame = a->anim_info.attack_down;
      break;

    default:
      a->base_frame = 0;
      break;
  }
}

BOOL animate_attack_actor(struct actor *a)
{
  BOOL is_done = FALSE;

  if (a->act == ATTACK)
  {
    if (++a->counter == a->anim_info.treshold)
    {
      if (++a->delta_frame > a->anim_info.num_attack_frames - 1)
      {
        set_dir_actor(a, a->dir);
        a->act = IDLE;
        is_done = TRUE;
      }

      a->counter = 0;
    }
  }

  return is_done;
}

void set_perished_actor(struct actor *a)
{
  a->act = PERISHED;
  a->base_frame = a->anim_info.perished;
  a->delta_frame = 0;
}

void face_target_actor(struct actor *a, struct actor *target)
{
  if (target->x < a->x)
    set_dir_actor(a, LEFT);
  else if (target->x > a->x)
    set_dir_actor(a, RIGHT);
  else if (target->y < a->y)
    set_dir_actor(a, UP);
  else if (target->y > a->y)
    set_dir_actor(a, DOWN);
}

void draw_actor(struct actor *a)
{
  draw_sprite(a->x - a->anim_info.anchor_x - d.map_x,
              a->y - a->anim_info.anchor_y - d.map_y,
              a->base_frame + a->delta_frame, a->spr,
              0, 0, screen_width, screen_height);
}

