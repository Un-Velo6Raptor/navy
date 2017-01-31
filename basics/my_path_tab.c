/*
** my_path_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 19:34:40 2017 
** Last update Mon Jan 30 21:12:29 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

int		length(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}

char		**my_path_tab(char *vpath)
{
  char		**path;
  int		path_i;
  int		str_i;
  int		vpath_i;

  if (!vpath || (path = malloc(sizeof(char *) * (length(vpath) + 1))) == NULL
      || (path[0] = malloc(sizeof(char) * length(vpath) + 1)) == NULL)
    return (NULL);
  path_i = 0;
  vpath_i = 0;
  while (vpath[vpath_i])
    {
      if (vpath[vpath_i] == ':' && vpath_i++)
	if ((path[path_i] = malloc(length(vpath) + 1)) == NULL)
	  return (NULL);
      str_i = 0;
      while (vpath[vpath_i] && vpath[vpath_i] != ':')
	path[path_i][str_i++] = vpath[vpath_i++];
      path[path_i][str_i] = '\0';
      path_i++;
    }
  path[path_i] = NULL;
  return (path);
}
