/*
** add_ship.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Feb  3 12:13:25 2017 
** Last update Sun Feb  5 23:00:50 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

int		found_the_good_ship(t_mode_background *mode)
{
  if (mode->ship_2 == 1)
    return (2);
  if (mode->ship_3 == 1)
    return (3);
  if (mode->ship_4 == 1)
    return (4);
  if (mode->ship_5 == 1)
    return (5);
  return (0);
}

sfVector2i	ship_already_add(char **map, int ship)
{
  int		idx;
  int		idx2;

  idx = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == ship + '0')
	    return (create_vector(idx2, idx));
	  idx2++;
	}
      idx++;
    }
  return (create_vector(-1, -1));
}

void		stop_button(char **map, t_mode_background *mode)
{
  if (nb_ship_place(map, 2) == 2)
    mode->ship_2 = 0;
  if (nb_ship_place(map, 3) == 3)
    mode->ship_3 = 0;
  if (nb_ship_place(map, 4) == 4)
    mode->ship_4 = 0;
  if (nb_ship_place(map, 5) == 5)
    mode->ship_5 = 0;
}

int		add_ship(t_my_framebuffer *buffer, t_mode_background *mode,
			 char ***map, sfVector2i pos)
{
  sfVector2i	tmp;
  int		the_ship;

  (void) buffer;
  if ((the_ship = found_the_good_ship(mode)) == 0)
    return (0);
  tmp = ship_already_add(*map, the_ship);
  if ((*map)[pos.y / 52][(pos.x - (WIDTH - 409)) / 51] != the_ship + '0' &&
      ((*map)[pos.y / 52][(pos.x - (WIDTH - 409)) / 51] != '.'))
    return (0);
  else if ((*map)[pos.y / 52][(pos.x -
			       (WIDTH - 409)) / 50] == the_ship + '0' &&
	   cross(*map, the_ship, create_vector((pos.x - (WIDTH - 409)) / 50,
					       pos.y / 52)) <= 1)
    (*map)[pos.y / 52][(pos.x -
			(WIDTH - 409)) / 51] = '.';
  else if (tmp.x == -1)
    (*map)[pos.y / 52][(pos.x -
			(WIDTH - 409)) / 51] = the_ship + '0';
  else
    check_the_ship(the_ship, map, create_vector((pos.x - (WIDTH - 409)) / 51,
						pos.y / 52), buffer);
  stop_button(*map, mode);
  return (0);
}
