/*
** update.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Feb  3 14:46:29 2017 
** Last update Sun Feb 19 22:08:04 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

void		disp_case(sfVector2i pos, t_my_framebuffer *buffer,
			  int the_ship)
{
  sfColor	color;
  sfVector2i	save;
  int		save_start;

  color = color_bouton(create_vector(the_ship, 0));
  pos.y = pos.y * 51;
  pos.x = pos.x * 51 + (WIDTH - 408);
  save_start = pos.x;
  save = create_vector(pos.x + 51, pos.y + 51);
  while (pos.y < save.y)
    {
      pos.x = save_start;
      while (pos.x <= save.x)
	{
	  my_put_pixel(buffer, pos.x, pos.y, color);
	  pos.x++;
	}
      pos.y++;
    }
}

void		update(char **map, t_my_framebuffer *buffer)
{
  int		idx;
  int		idx2;

  idx = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] != '.')
	    disp_case(create_vector(idx2, idx), buffer, map[idx][idx2] - '0');
	  idx2++;
	}
      idx++;
    }
}
