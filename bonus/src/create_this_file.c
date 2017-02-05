/*
** create_this_file.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Feb  3 21:21:48 2017 
** Last update Sat Feb  4 02:31:03 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"my.h"

sfVector2i	found_the_last(char **map, int the_ship)
{
  sfVector2i	tmp;
  int		idx;
  int		idx2;

  idx = 0;
  tmp = create_vector(0, 0);
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == the_ship + '0')
	    tmp = create_vector(idx2, idx);
	  idx2++;
	}
      idx++;
    }
  return (tmp);
}

sfVector2i	found_the_first(char **map, int the_ship)
{
  int		idx;
  int		idx2;

  idx = 0;
  while (map[idx] != NULL)
    {
      idx2 = 0;
      while (map[idx][idx2] != '\0')
	{
	  if (map[idx][idx2] == the_ship + '0')
	    return (create_vector(idx2, idx));
	  idx2++;
	}
      idx++;
    }
  return (create_vector(0, 0));
}

int		write_this_file(FILE *file, char **map)
{
  sfVector2i	from;
  sfVector2i	to;
  int		idx;

  idx = 2;
  while (idx <= 5)
    {
      from = found_the_first(map, idx);
      to = found_the_last(map, idx);
      fprintf(file, "%d:%c%d:%c%d\n", idx, from.x + 'A',
	      from.y + 1, to.x + 'A', to.y + 1);
      idx++;
    }
  return (0);
}

int		create_this_file(char *name, char **map)
{
  char		str[my_strlen(name) + my_strlen("map_create/") + 1];
  struct stat	sb;
  FILE		*file;

  my_strcpy(str, "map_create/");
  my_strcat(str, name);
  file = NULL;
  if (lstat(str, &sb) != -1)
    {
      my_puterror("File already exist\n");
      return (0);
    }
  if ((file = fopen(str, "w")) == NULL)
    return (84);
  write_this_file(file, map);
  if (fclose(file) != 0)
    return (84);
  return (0);
}
