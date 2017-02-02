/*
** bite.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 14:25:13 2017 Sahel
** Last update Thu Feb  2 11:42:12 2017 Lucas Sahel
*/

#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"battleship.h"

t_glob	*g_glob;

int		init_glob(char **av)
{
  if ((g_glob = malloc(sizeof(t_glob))) == NULL)
    return (84);
  if ((g_glob->av = malloc(sizeof(char *) * 4)) == NULL)
    return (84);
  if ((g_glob->av[0] = my_strdup(av[0])) == NULL)
    return (84);
  if ((g_glob->av[1] = my_strdup(av[1])) == NULL)
    return (84);
  if (av[2])
    {
      if ((g_glob->av[2] = my_strdup(av[2])) == NULL)
	return (84);
      g_glob->av[3] = NULL;
    }
  else
    g_glob->av[2] = NULL;
  return (0);
}

int			client(char **av)
{
  t_map			*maps;

  g_glob->pid = my_getnbr(av[1]);
  kill(g_glob->pid, SIGUSR1);
  
  signal(SIGUSR1, &connect2);
  pause();
  if (!(maps = ini_map()) ||
      prepare_map(maps, count_tab(g_glob->av), g_glob->av) == 84)
    return (84);
  turn_part1(maps->my_map, maps->enemy_map, my_getnbr(av[1]), 2);
  return (0);
}

int			main(int ac, char **av)
{
  struct sigaction	act;
  t_map			*maps;

  if (ac == 1 || ac > 3 || init_glob(av) == 84)
    return (help_me());
  act.sa_sigaction = &connect;
  act.sa_flags = SA_SIGINFO;
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  my_putstr("\n");
  if (ac == 2)
    {
      my_putstr("waiting for ennemy connexion...\n");
      sigaction(SIGUSR1, &act, NULL);
      pause();
      if (!(maps = ini_map()) ||
	  prepare_map(maps, count_tab(g_glob->av), g_glob->av) == 84)
	return (84);
      turn_part2(maps->my_map, maps->enemy_map, g_glob->pid, 1);
    }
  else
    return (client(av));
}
