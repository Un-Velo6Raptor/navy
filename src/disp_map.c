/*
** disp_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 17:31:31 2017 
** Last update Fri Feb 17 11:21:39 2017 Sahel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"battleship.h"

void		my_putchar(char f)
{
  write(1, &f, 1);
}

void		disp_map(char **map)
{
  int		idx;

  idx = 0;
  my_putstr(" |A B C D E F G H\n");
  my_putstr("-+---------------\n");
  while (map[idx] != NULL)
    {
      my_putchar((idx + 1) + '0');
      my_putchar('|');
      my_putstr(map[idx]);
      my_putchar('\n');
      idx++;
    }
}

void		disp_my_and_enemy_map(char **map, char **map2)
{
  my_putstr("my positions:\n");
  disp_map(map);
  my_putstr("\nenemy's positions:\n");
  disp_map(map2);
  my_putstr("\n");
}
