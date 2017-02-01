/*
** game.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 17:24:11 2017 Sahel
** Last update Wed Feb  1 16:21:54 2017 
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "battleship.h"

extern t_glob	*g_glob;

int		is_valid(char *str)
{
  if (my_strlen(str) != 2)
    {
      my_putstr("wrong position\nattack:\t");
      return (0);
    }
  if ((str[0] >= 'A' && str[0] <= 'H') &&
      (str[1] >= '1' && str[1] <= '8'))
    return (1);
  my_putstr("wrong position\nattack:\t");
  return (0);
}

void	start(int signal)
{
  (void) signal;
}

char	check_xo(char **map, char *action)
{
  char	map_char;

  map_char = map[action[1] - '1'][(action[0] - 'A') * 2];
  if (map_char == '.' || map_char == 'o')
    return ('o');
  return ('x');
}

void	get_enemy_id(int sig, siginfo_t *si, void *null)
{
  (void) null;
  (void) sig;
  g_glob->last_pid = si->si_pid;
}

int	turn_part2(char **map, char **map2, int pid, int player)
{
  struct sigaction act;
  char	action[3];
  char	xoxo;

  if (player == 1)
    disp_my_and_enemy_map(map, map2);
  my_putstr("waiting for enemy's attack...\n");
  sigemptyset(&act.sa_mask);
  act.sa_sigaction = &get_enemy_id;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &act, NULL);
  pause();
  if (g_glob->pid != g_glob->last_pid)
    return (84);
  if ((action[0] = my_binary_to_char(receive(pid))) == '\0' ||
      (action[1] = my_binary_to_char(receive(pid))) == '\0')
    return (84);
  write(1, action, 2);
  xoxo = check_xo(map, action);
  my_putstr((xoxo == 'o') ? ":\tmissed\n\n" : ":\thit\n\n");
  map[action[1] - '1'][(action[0] - 'A') * 2] = xoxo;
  usleep(300000);
  send(pid, my_char_to_binary(xoxo));
  turn_part1(map, map2, pid, player);
  return (0);
}

int		turn_part1(char **map, char **map2, int pid, int player)
{
  char		*action;
  t_buffer	gnl;
  char		xoxo;

  ini_gnl(&gnl);
  if (player == 2)
    disp_my_and_enemy_map(map, map2);
  my_putstr("attack:\t");
  while (!is_valid(action = get_next_line(0, &gnl)));
  my_putstr(action);
  my_putstr(":\t");
  kill(pid, SIGUSR1);
  usleep(10000);
  send(pid, my_char_to_binary(action[0]));
  send(pid, my_char_to_binary(action[1]));
  usleep(170000);
  if ((xoxo = my_binary_to_char(receive(pid))) == '\0')
    return (84);
  my_putstr((xoxo == 'o') ? "missed\n\n" : "hit\n\n");
  map2[action[1] - '1'][(action[0] - 'A') * 2] = xoxo;
  turn_part2(map, map2, pid, player);
  return (0);
}
