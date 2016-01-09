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

  a->curr_base_frame = 0;
  a->curr_delta_frame = 1;
  a->curr_frame = 0;
  a->counter = 0;
}

void move_actor(struct actor *a, byte dx, byte dy)
{
  if (dx)
  {
    a->dx = dx;

    if (dx < 0)
    {
      a->curr_base_frame = ACTOR_FRAME_LEFT;
    }
    else if (dx > 0) {
      a->curr_base_frame = ACTOR_FRAME_RIGHT;
    }

    a->is_moving = TRUE;
  }

  if (dy)
  {
    a->dy = dy;

    if (dy < 0)
    {
      a->curr_base_frame = ACTOR_FRAME_UP;
    }
    else if (dy > 0) {
      a->curr_base_frame = ACTOR_FRAME_DOWN;
    }

    a->is_moving = TRUE;
  }
}

void animate_actor(struct actor *a)
{
  if (a->is_moving == TRUE)
  {
    if (++a->counter == ACTOR_ANIM_TRESHOLD)
    {
      if (++a->curr_delta_frame == 2)
      {
        a->curr_delta_frame = 0;
      }

      a->counter = 0;
    }

    if (a->dx)
    {
      a->x += a->dx * ACTOR_SPEED;
      if ((a->x % TILE_WIDTH) == 0)
      {
        a->dx = 0;
        a->curr_delta_frame = 1;
        a->is_moving = FALSE;
      }
    }

    if (a->dy)
    {
      a->y += a->dy * ACTOR_SPEED;
      if ((a->y % TILE_HEIGHT) == 0)
      {
        a->dy = 0;
        a->curr_delta_frame = 1;
        a->is_moving = FALSE;
      }
    }
  }

  a->curr_frame = a->curr_base_frame + a->curr_delta_frame;
}

void draw_actor(struct actor *a)
{
  draw_sprite(a->x - d.map_x, a->y - d.map_y, a->curr_frame, a->spr,
              0, 0, screen_width, screen_height);
}

