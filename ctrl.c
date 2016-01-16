/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
*
*   This file is part of yz.
*   Copyright (C) 2014 Surplus Users Ham Society
*
*   Yz is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 2 of the License, or
*   (at your option) any later version.
*
*   Yz is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public License
*   along with Yz.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "ctrl.h"

int get_input(void)
{
  int input = 0;
  Uint8 *keys = SDL_GetKeyState(NULL);

  if(keys[SDLK_ESCAPE])
    input=SET_BITS(input,PRESS_ESC);

  if(keys[SDLK_UP])
    input=SET_BITS(input,PRESS_UP);

  if(keys[SDLK_RIGHT])
    input=SET_BITS(input,PRESS_RIGHT);

  if(keys[SDLK_LEFT])
    input=SET_BITS(input,PRESS_LEFT);

  if(keys[SDLK_DOWN])
    input=SET_BITS(input,PRESS_DOWN);

  if(keys[SDLK_RETURN])
    input=SET_BITS(input,PRESS_ENTER);

  if(keys[SDLK_SPACE])
    input=SET_BITS(input,PRESS_FIRE);

  if(keys[SDLK_PAGEUP])
    input=SET_BITS(input,PRESS_ADVANCE);

  if(keys[SDLK_PAGEDOWN])
    input=SET_BITS(input,PRESS_REVERT);

  return input;
}

int get_input_keydown(int ks)
{
  int input = 0;

   switch(ks)
   {
      case SDLK_ESCAPE:
	 input=SET_BITS(input,PRESS_ESC);
	 break;
      case SDLK_UP:
         input=SET_BITS(input,PRESS_UP);
         break;
      case SDLK_RIGHT:
         input=SET_BITS(input,PRESS_RIGHT);
         break;
      case SDLK_LEFT:
         input=SET_BITS(input,PRESS_LEFT);
         break;
      case SDLK_DOWN:
         input=SET_BITS(input,PRESS_DOWN);
         break;
      case SDLK_RETURN:
         input=SET_BITS(input,PRESS_ENTER);
         break;
      case SDLK_SPACE:
         input=SET_BITS(input,PRESS_FIRE);
         break;
      case SDLK_PAGEUP:
         input=SET_BITS(input,PRESS_ADVANCE);
         break;
      case SDLK_PAGEDOWN:
         input=SET_BITS(input,PRESS_REVERT);
         break;
      default: break;
   }

   return input;
}

int get_input_keyup(int ks)
{
  int input = 0;

   switch(ks)
   {
      case SDLK_ESCAPE:
	 input=RESET_BITS(input,PRESS_ESC);
	 break;
      case SDLK_UP:
         input=RESET_BITS(input,PRESS_UP);
         break;
      case SDLK_RIGHT:
         input=RESET_BITS(input,PRESS_RIGHT);
         break;
      case SDLK_LEFT:
         input=RESET_BITS(input,PRESS_LEFT);
         break;
      case SDLK_DOWN:
         input=RESET_BITS(input,PRESS_DOWN);
         break;
      case SDLK_RETURN:
         input=RESET_BITS(input,PRESS_ENTER);
         break;
      case SDLK_SPACE:
         input=RESET_BITS(input,PRESS_FIRE);
         break;
      case SDLK_PAGEUP:
         input=RESET_BITS(input,PRESS_ADVANCE);
         break;
      case SDLK_PAGEDOWN:
         input=RESET_BITS(input,PRESS_REVERT);
         break;
      default: break;
   }

   return input;
}

