/*
** check_the_ship.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Feb  3 13:23:41 2017 
** Last update Fri Feb  3 14:19:12 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<stdio.h>
#include	"my.h"

int		cross(char **map, int the_ship, sfVector2i pos)
{
  int		idx;

  idx = 0;
  if (pos.y - 1 >= 0 && map[pos.y - 1][pos.x] == the_ship + '0')
    idx++;
  if (pos.y + 1 <= 7 && map[pos.y + 1][pos.x] == the_ship + '0')
    idx++;
  if (pos.x + 1 <= 7 && map[pos.y][pos.x + 1] == the_ship + '0')
    idx++;
  if (pos.x - 1 >= 0 && map[pos.y][pos.x - 1] == the_ship + '0')
    idx++;
  return (idx);
}

int		nb_ship_place(char **map, int the_ship)
{
  int		idx;
  int		idx2;
  int		result;

  idx = 0;
  result = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == the_ship + '0')
	    result++;
	  idx2++;
	}
      idx++;
    }
  return (result);
}

int		check_alignement(char **map, int the_ship, sfVector2i pos)
{
  if (pos.y - 1 >= 0 && pos.y - 2 >= 0 &&
      map[pos.y - 1][pos.x] == the_ship + '0' &&
      map[pos.y - 2][pos.x] == the_ship + '0')
    return (0);
  if (pos.y + 1 <= 7 && pos.y + 2 <= 7 &&
      map[pos.y + 1][pos.x] == the_ship + '0' &&
      map[pos.y + 2][pos.x] == the_ship + '0')
    return (0);
  if (pos.x - 1 >= 0 && pos.x - 2 >= 0 &&
      map[pos.y][pos.x - 1] == the_ship + '0' &&
      map[pos.y][pos.x - 2] == the_ship + '0')
    return (0);
  if (pos.x + 1 >= 0 && pos.x + 2 >= 0 &&
      map[pos.y][pos.x + 1] == the_ship + '0' &&
      map[pos.y][pos.x + 2] == the_ship + '0')
    return (0);
  return (1);
}

int		check_the_ship(int the_ship, char ***map,
			       sfVector2i pos, t_my_framebuffer *buffer)
{
  int		idx;

  (void) buffer;
  if (cross(*map, the_ship, pos) == 0 ||
      (idx = nb_ship_place(*map, the_ship)) >= the_ship)
    return (0);
  if (idx == 1)
    (*map)[pos.y][pos.x] = the_ship + '0';
  else if (check_alignement(*map, the_ship, pos) == 0)
    (*map)[pos.y][pos.x] = the_ship + '0';
  return (0);
}
