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

  a->base_frame = 0;
  a->delta_frame = 1;
  a->counter = 0;

  memcpy(&a->anim_info, info, sizeof(struct anim_info));
}

void set_dir_actor(struct actor *a, enum facing dir)
{
  a->dir = dir;

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

void move_actor(struct actor *a, byte dx, byte dy)
{
  if (dx)
  {
    a->dx = dx;
    a->is_moving = TRUE;
  }

  if (dy)
  {
    a->dy = dy;
    a->is_moving = TRUE;
  }
}

void animate_actor(struct actor *a)
{
  if (a->is_moving == TRUE)
  {
    if (++a->counter == a->anim_info.treshold)
    {
      if (++a->delta_frame == 2)
      {
        a->delta_frame = 0;
      }

      a->counter = 0;
    }

    if (a->dx)
    {
      a->x += a->dx * a->anim_info.speed;
      if ((a->x % TILE_WIDTH) == 0)
      {
        a->dx = 0;
        a->delta_frame = 1;
        a->is_moving = FALSE;
      }
    }

    if (a->dy)
    {
      a->y += a->dy * a->anim_info.speed;
      if ((a->y % TILE_HEIGHT) == 0)
      {
        a->dy = 0;
        a->delta_frame = 1;
        a->is_moving = FALSE;
      }
    }
  }
}

void draw_actor(struct actor *a)
{
  draw_sprite(a->x - d.map_x, a->y - d.map_y,
              a->base_frame + a->delta_frame, a->spr,
              0, 0, screen_width, screen_height);
}

