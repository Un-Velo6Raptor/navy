/*
** create_map.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:58:34 2017 
** Last update Wed Feb  1 22:07:26 2017 
*/

#include	<stdlib.h>
#include	"my.h"

char		**create_map(void)
{
  char		**map;
  int		idx;

  idx = 0;
  if ((map = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  while (idx < 8)
    {
      if ((map[idx] = my_strdup("........")) == NULL)
	return (NULL);
      idx++;
    }
  map[idx] = NULL;
  return (map);
}
