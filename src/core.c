/*
** bite.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 14:25:13 2017 Sahel
** Last update Thu Feb  9 16:02:31 2017 Sahel
*/

#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"battleship.h"

t_glob	*g_glob;

int		init_glob()
{
  if ((g_glob = malloc(sizeof(t_glob))) == NULL)
    return (84);
  return (0);
}

int			client(char **av, t_map *maps)
{
  g_glob->pid = my_getnbr(av[1]);
  kill(g_glob->pid, SIGUSR1);
  signal(SIGUSR1, &connect2);
  pause();
  return (turn_part2(maps->my_map, maps->enemy_map, my_getnbr(av[1]), 2));
}

int			main(int ac, char **av)
{
  struct sigaction	act;
  t_map			*maps;

  if (ac == 1 || ac > 3 || init_glob(av) == 84)
    return (help_me());
  if (!(maps = ini_map()) ||
      prepare_map(maps, count_tab(av), av) == 84)
    return (84);
  act.sa_sigaction = &connect;
  act.sa_flags = SA_SIGINFO;
  sigemptyset(&act.sa_mask);
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  my_putstr("\n");
  if (ac == 2)
    {
      my_putstr("waiting for enemy connection...\n");
      sigaction(SIGUSR1, &act, NULL);
      pause();
      usleep(100000);
      return (turn_part1(maps->my_map, maps->enemy_map, g_glob->pid, 1));
    }
  else
    return (client(av, maps));
}
