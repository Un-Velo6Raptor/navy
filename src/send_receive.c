/*
** send_receive.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Jan 31 21:21:25 2017 
** Last update Thu Feb  9 15:59:12 2017 Sahel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<signal.h>
#include	"battleship.h"

extern t_glob	*g_glob;

void		change_byte(int sig)
{
  if (sig == SIGUSR1)
    g_glob->byte = '0';
  else
    g_glob->byte = '1';
}

void			change()
{
  struct sigaction      act;

  sigemptyset(&act.sa_mask);
  act.sa_handler = &change_byte;
  act.sa_flags = 0;
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
}

char		*receive(int pid)
{
  int		cpt;
  char		*binary;

  if ((binary = malloc(9)) == NULL)
    return (NULL);
  cpt = 0;
  while (cpt < 8)
    {
      g_glob->byte = '0';
      change();
      pause();
      binary[cpt] = g_glob->byte;
      cpt++;
      usleep(5000);
      kill(pid, SIGUSR1);
    }
  binary[cpt] = '\0';
  return (binary);
}

void		send(int pid, char *binary)
{
  int		idx;

  idx = 0;
  while (idx < 8)
    {
      usleep(10000);
      if (binary[idx] == '0')
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      idx++;
      signal(SIGUSR1, &change_byte);
      pause();
    }
}

