/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:36:47 2017 
** Last update Mon Jan 30 18:53:23 2017 
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"battleship.h"

int		add_ship(t_map *all_map, char *ship)
{
  if (my_strlen(ship) != 7)
    return (my_puterror("Error in the file.\n"));
  return (0);
}

int		prepare_map(t_map *all_map, int argc, char **av)
{
  char		*str;
  int		fd;

  (argc == 2) ? (fd = open(av[2], O_RDONLY)) : (fd = open(av[1], O_RDONLY));
  if (fd == -1)
    return (my_puterror("Can't open the file.\n"));
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((add_ship(all_map, str)) == 84)
	{
	  free(str);
	  return (84);
	}
      free(str);
    }
  if (close(fd) == -1)
    return (my_puterror("Can't close the file.\n"));
  return (0);
}

int		main(int argc, char **argv)
{
  t_map		*all_map;

  if (argc == 1 || argc > 2)
    return (help_me());
  (void)argv;
  if ((all_map = ini_map()) == NULL)
    return (84);
  if (prepare_map(all_map, argc, argv) == 84)
    return (84);
  disp_map(all_map->my_map);
  return (0);
}
