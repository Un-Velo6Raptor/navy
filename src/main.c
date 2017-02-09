/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:36:47 2017 
** Last update Thu Feb  9 15:44:55 2017 
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"battleship.h"
#include	"gnl.h"

int		free_this(char *str)
{
  if (str != NULL)
    free(str);
  return (84);
}

int		change_map(t_map *all_map, char size, char *s1, char *s2)
{
  while (my_strcmp(s1, s2) != 0)
    {
      if (all_map->my_map[(s1[1] - '1')][(s1[0] - 'A') * 2] != '.')
	return (84);
      all_map->my_map[(s1[1] - '1')][(s1[0] - 'A') * 2] = size;
      if (s1[0] == s2[0])
	{
	  if (s1[1] < s2[1])
	    s1[1] = s1[1] + 1;
	  else
	    s2[1] = s2[1] - 1;
	}
      else
	{
	  if (s1[0] < s2[0])
	    s1[0] = s1[0] + 1;
	  else
	    s2[0] = s2[0] - 1;
	}
    }
  if (all_map->my_map[(s1[1] - '1')][(s1[0] - 'A') * 2] != '.')
    return (84);
  all_map->my_map[(s1[1] - '1')][(s1[0] - 'A') * 2] = size;
  return (0);
}

int		add_ship(t_map *all_map, char *ship)
{
  char		**tab;

  if (my_strlen(ship) != 7)
    return (my_puterror("Error in the file.\n"));
  if ((tab = my_path_tab(ship)) == NULL)
    return (84);
  if (my_strlen(tab[0]) != 1 || my_char_isnum(tab[0][0]) != 0 ||
      count_tab(tab) != 3)
    return (free_tab(tab, 84));
  if (check_coo(my_getnbr(tab[0]), tab[1], tab[2]) == 84)
    return (free_tab(tab, 84));
  if (change_map(all_map, tab[0][0], tab[1], tab[2]) == 84)
    return (free_tab(tab, 84));
  return (free_tab(tab, 0));
}

int		prepare_map(t_map *all_map, int argc, char **av)
{
  char		*str;
  int		fd;
  int		idx;

  idx = 0;
  if ((fd = open((argc == 3) ? av[2] : av[1], O_DIRECTORY)) > 0)
    {
      close(fd);
      return (my_puterror("Not a file.\n"));
    }
  if ((fd = open((argc == 3) ? av[2] : av[1], O_RDONLY)) == -1)
    return (my_puterror("Can't open the file.\n"));
  while ((str = get_next_line(fd)) != NULL)
    {
      str = my_good_str(str);
      if ((add_ship(all_map, str)) == 84)
	return (free_this(str));
      idx++;
      free(str);
    }
  if (close(fd) == -1)
    return (my_puterror("Can't close the file.\n"));
  return ((idx != 4) ? 84 : 0);
}
