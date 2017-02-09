/*
** connect.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Jan 31 21:25:19 2017 
** Last update Thu Feb  9 15:42:35 2017 Sahel
*/

#include	<stdio.h>
#include	<signal.h>
#include	<unistd.h>
#include	"battleship.h"

extern t_glob	*g_glob;

void		connect(int signal, siginfo_t *act, void *null)
{
  (void) signal;
  (void) null;
  g_glob->pid = act->si_pid;
  my_putstr("\nenemy connected\n\n");
  usleep(10000);
  kill(g_glob->pid, SIGUSR1);
}

void		connect2(int signal)
{
  (void) signal;
  my_putstr("successfully connected\n\n");
}

void		start(int signal)
{
  (void) signal;
}

void		get_enemy_id(int sig, siginfo_t *si, void *null)
{
  (void) null;
  (void) sig;
  g_glob->last_pid = si->si_pid;
}
