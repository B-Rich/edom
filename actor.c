#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "main.h"

void init_actor(struct actor *a, const char *fn, int w, int h)
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
}

void set_dir_actor(struct actor *a, enum facing dir)
{
  a->dir = dir;

  switch (dir)
  {
    case LEFT:
      a->base_frame = ACTOR_FRAME_LEFT;
      break;

    case RIGHT:
      a->base_frame = ACTOR_FRAME_RIGHT;
      break;

    case UP:
      a->base_frame = ACTOR_FRAME_UP;
      break;

    case DOWN:
      a->base_frame = ACTOR_FRAME_DOWN;
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
    if (++a->counter == ACTOR_ANIM_TRESHOLD)
    {
      if (++a->delta_frame == 2)
      {
        a->delta_frame = 0;
      }

      a->counter = 0;
    }

    if (a->dx)
    {
      a->x += a->dx * ACTOR_SPEED;
      if ((a->x % TILE_WIDTH) == 0)
      {
        a->dx = 0;
        a->delta_frame = 1;
        a->is_moving = FALSE;
      }
    }

    if (a->dy)
    {
      a->y += a->dy * ACTOR_SPEED;
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

