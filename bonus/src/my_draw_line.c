/*
** my_draw_line.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:06:41 2017 
** Last update Thu Feb  2 14:05:54 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

void	display_2(t_my_framebuffer *frame_buffer, sfVector2i from,
		  sfColor color, int *tb)
{
  int	xinc;
  int	yinc;
  int	cumul;
  int	i;

  i = 1;
  xinc = tb[2];
  yinc = tb[3];
  cumul = tb[1] / 2;
  while (i <= tb[1])
    {
      from.y += yinc;
      cumul += tb[0];
      if (cumul > tb[1])
	{
	  cumul -= tb[1];
	  from.x += xinc;
	}
      my_put_pixel(frame_buffer, from.x, from.y, color);
      i++;
    }
}

void	display_1(t_my_framebuffer *frame_buffer, sfVector2i from,
		  sfColor color, int *tb)
{
  int	xinc;
  int	yinc;
  int	cumul;
  int	i;

  i = 1;
  xinc = tb[2];
  yinc = tb[3];
  cumul = tb[0] / 2;
  while (i <= tb[0])
    {
      from.x += xinc;
      cumul += tb[1];
      if (cumul >= tb[0])
	{
	  cumul -= tb[0];
	  from.y += yinc;
	}
      my_put_pixel(frame_buffer, from.x, from.y, color);
      i++;
    }
}

void	my_draw_line(t_my_framebuffer *frame_buffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int	tb[4];
  int	dx;
  int	dy;

  dx = to.x - from.x;
  dy = to.y - from.y;
  tb[0] = (dx < 0) ? (dx * -1) : (dx);
  tb[1] = (dy < 0) ? (dy * -1) : (dy);
  tb[2] = ((dx > 0) ? (1) : (-1));
  tb[3] = ((dy > 0) ? (1) : (-1));
  my_put_pixel(frame_buffer, from.x, from.y, color);
  if (tb[0] > tb[1])
    display_1(frame_buffer, from, color, tb);
  else
    display_2(frame_buffer, from, color, tb);
}
