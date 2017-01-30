/*
** my_str_to_wordtab.c for Pool 08 in /home/H3r3zy/rendu/CPool_Day08/task04
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Wed Oct 12 15:19:40 2016 Lucas Sahel
** Last update Sun Jan 22 15:51:59 2017 Sahel
*/

#include <stdlib.h>
#include "main.h"

char	**my_path_tab(char *vpath)
{
  char	**path;
  int	path_i;
  int	str_i;
  int	vpath_i;

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
  free(vpath);
  path[path_i] = NULL;
  return (path);
}
