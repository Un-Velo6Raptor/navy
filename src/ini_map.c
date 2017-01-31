/*
** ini_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 17:11:26 2017 
** Last update Mon Jan 30 17:46:50 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

char		**create_map()
{
  char		**tab;
  int		idx;

  idx = 0;
  if ((tab = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  while (idx < 8)
    {
      if ((tab[idx] = my_strdup(". . . . . . . .")) == NULL)
	return (NULL);
      idx++;
    }
  tab[idx] = NULL;
  return (tab);
}

t_map		*ini_map(void)
{
  t_map		*all_map;

  if ((all_map = malloc(sizeof(t_map) * 1)) == NULL)
    return (NULL);
  if ((all_map->my_map = create_map()) == NULL ||
      (all_map->enemy_map = create_map()) == NULL)
    return (NULL);
  return (all_map);
}
