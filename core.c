/*
** bite.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 14:25:13 2017 Sahel
** Last update Mon Jan 30 18:50:36 2017 Sahel
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	byte;

void	change_byte(int sig)
{
  if (sig == SIGUSR1)
    byte = '0';
  else
    byte = '1';
}

void	change()
{
  signal(SIGUSR2, change_byte);
  signal(SIGUSR1, change_byte);
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
      byte = '0';
      change();
      sleep(10);
      binary[cpt] = byte;
      printf("%c\n", byte);
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
  while (idx < 8)
    {
      printf("%c\n", binary[idx]);
      if (binary[idx] == '0')
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      idx++;
      signal(SIGUSR1, change_byte);
      sleep(1);
    }
}

void	connect(int signal, siginfo_t *act, void *null)
{
  int	pid2;

  (void) signal;
  pid2 = act->si_pid;
  printf("ennemy connected\n");
  kill(pid2, SIGUSR1);
  usleep(100000);
  turn_part2(map, map2, pid2);
}

void	connect2(int signal)
{
  (void) signal;
  printf("successfully connected\n");
}

int			main(int ac, char **av)
{
  struct sigaction	act;

  act.sa_sigaction = &connect;
  act.sa_flags = SA_SIGINFO;
  printf("my_pid:\t%i\n", getpid());
  if (ac == 1)
    {
      printf("waiting for ennemy connexion...\n");
      sigaction(SIGUSR1, &act, NULL);
      sleep(100);
    }
  else
    {
      kill(atoi(av[1]), SIGUSR1);
      signal(SIGUSR1, connect2);
      sleep(20);
      turn_part1(map, map2, atoi(av[1]));
    }
}
