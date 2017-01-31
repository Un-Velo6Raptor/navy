/*
** bite.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 14:25:13 2017 Sahel
** Last update Tue Jan 31 18:50:56 2017 Sahel
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "battleship.h"

t_glob	*g_glob;

void	change_byte(int sig)
{
  if (sig == SIGUSR1)
    g_glob->byte = '0';
  else
    g_glob->byte = '1';
}

void	change()
{
  struct sigaction	act;

  sigemptyset(&act.sa_mask);
  act.sa_handler = &change_byte;
  act.sa_flags = 0;
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
}

char	*receive(int pid)
{
  int	cpt;
  char	*binary;

  if ((binary = malloc(9)) == NULL)
    return (NULL);
  cpt = 0;
  while (cpt < 8)
    {
      g_glob->byte = '0';
      change();
      usleep(500000);
      binary[cpt] = g_glob->byte;
      cpt++;
      kill(pid, SIGUSR1);
    }
  binary[cpt] = '\0';
  return (binary);
}

void	send(int pid, char *binary)
{
  int	idx;

  idx = 0;
  //printf("%s\n", binary);
  while (idx < 8)
    {
      if (binary[idx] == '0')
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      idx++;
      signal(SIGUSR1, &change_byte);
      usleep(700000);
    }
}

void	connect(int signal, siginfo_t *act, void *null)
{
  (void) signal;
  (void) null;
  g_glob->pid = act->si_pid;
  printf("ennemy connected\n\n");
  usleep(100000);
  kill(g_glob->pid, SIGUSR1);
}

void	connect2(int signal)
{
  (void) signal;
  printf("successfully connected\n\n");
}

void	init_glob(char **av)
{
  g_glob = malloc(sizeof(t_glob));
  g_glob->av = malloc(sizeof(char *) * 4);
  g_glob->av[0] = my_strdup(av[0]);
  g_glob->av[1] = my_strdup(av[1]);
  if (av[2])
    {
      g_glob->av[2] = my_strdup(av[2]);
      g_glob->av[3] = NULL;
    }
  else
    g_glob->av[2] = NULL;
}

int			main(int ac, char **av)
{
  struct sigaction	act;
  t_map			*maps;

  if (ac == 1 || ac > 3)
    return (help_me());
  init_glob(av);
  act.sa_sigaction = &connect;
  act.sa_flags = SA_SIGINFO;
  printf("my_pid:\t%i\n", getpid());
  if (ac == 2)
    {
      printf("waiting for ennemy connexion...\n");
      sigaction(SIGUSR1, &act, NULL);
      pause();
      if (!(maps = ini_map()) || prepare_map(maps, count_tab(g_glob->av), g_glob->av) == 84)
	return (84);
      turn_part2(maps->my_map, maps->enemy_map, g_glob->pid, 1);
    }
  else
    {
      kill(atoi(av[1]), SIGUSR1);
      signal(SIGUSR1, &connect2);
      sleep(2);
      if (!(maps = ini_map()) || prepare_map(maps, count_tab(g_glob->av), g_glob->av) == 84)
	return (84);
      turn_part1(maps->my_map, maps->enemy_map, atoi(av[1]), 2);
    }
}
