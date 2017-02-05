/*
** bouton_display.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb  2 18:38:24 2017 
** Last update Fri Feb  3 17:16:39 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"framefuffer.h"
#include	"my.h"

sfColor		color_bouton(sfVector2i mode)
{
  sfColor	color;

  if (mode.x == 2)
    color = set_pixel_color(223, 109, 20);
  else if (mode.x == 3)
    color = set_pixel_color(253, 108, 158);
  else if (mode.x == 4)
    color = set_pixel_color(102, 109, 20);
  else if (mode.x == 5)
    color = set_pixel_color(4, 139, 154);
  if (mode.y == 0)
    color.a = 255;
  else
    color.a = 255 / 2;
  return (color);
}

void		bouton(t_my_framebuffer *buffer, sfVector2i mode,
		       sfVector2i from, sfVector2i to)
{
  sfColor		color;

  color = color_bouton(mode);
  while (from.y != to.y)
    {
      my_draw_line(buffer, create_vector(from.x, from.y),
		   create_vector(to.x, from.y), color);
      from.y += 1;
    }
}

void		bouton_display(t_mode_background *mode, t_my_framebuffer *buffer)
{
  bouton(buffer, create_vector(2, mode->ship_2), create_vector(31, 1),
	 create_vector(WIDTH - 409, HEIGHT / 5));
  bouton(buffer, create_vector(3, mode->ship_3), create_vector(31, 1 + (HEIGHT / 5)),
	 create_vector(WIDTH - 409, (HEIGHT / 5) * 2));
  bouton(buffer, create_vector(4, mode->ship_4), create_vector(31, 1 + (HEIGHT / 5) * 2),
	 create_vector(WIDTH - 409, (HEIGHT / 5) * 3));
  bouton(buffer, create_vector(5, mode->ship_5), create_vector(31, 1 + (HEIGHT / 5) * 3),
	 create_vector(WIDTH - 409, (HEIGHT / 5) * 4));
}
