/*
** bite.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 14:25:13 2017 Sahel
** Last update Mon Jan 30 14:42:37 2017 Sahel
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	connect(int signal)
{
  (void) signal;
  printf("ennemy connected");
}

void	success_connect(int signal)
{
  (void) signal;
  printf("successfully connected\n");
}

void	first_player()
{
  printf("my_pid:\t%i\n", getpid());
  printf("waiting for ennemy connexion...\n");
  while (1);
  signal(SIGUSR1, connect);
}

void	second_player(char *pid1)
{
  printf("my_pid:\t%i\n", getpid());
  kill(atoi(pid1), SIGUSR1);
  signal(SIGUSR2, success_connect); 
}

int	main(int ac, char **av)
{
  if (ac == 1)
    {
      first_player();
    }
  else
    {
      second_player(av[1]);
    }
}
