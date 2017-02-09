/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:01:24 2017 
** Last update Sun Feb  5 23:01:00 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		main(int argc, char **argv)
{
  char		**map;

  if (argc != 2 || my_strcmp(argv[1], "-h") != 1 ||
      check_namme(argv[1]) == 84)
    return (help_me());
  if ((map = create_map()) == NULL)
    return (84);
  if (ini_window(map, argv[1]) == 84)
    return (84);
  free_tab(map);
  return (0);
}
