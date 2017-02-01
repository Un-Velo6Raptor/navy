/*
** game.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 17:24:11 2017 Sahel
** Last update Wed Feb  1 10:56:26 2017 Sahel
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "battleship.h"

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

void	turn_part2(char **map, char **map2, int pid, int player)
{
  char	action[3];
  char	xoxo;

  if (player == 1)
    disp_my_and_enemy_map(map, map2);
  my_putstr("waiting for enemy's attack...\n");
  signal(SIGUSR1, start);
  pause();
  action[0] = my_binary_to_char(receive(pid));
  action[1] = my_binary_to_char(receive(pid));
  action[2] = '\0';
  my_putstr(action);
  xoxo = check_xo(map, action);
  (xoxo == 'o') ? my_putstr(":\tmissed\n\n") : my_putstr(":\thit\n\n"); // IDEM QUE PART 1
  map[action[1] - '1'][(action[0] - 'A') * 2] = xoxo;
  usleep(300000);
  send(pid, my_char_to_binary(xoxo));
  turn_part1(map, map2, pid, player);
}

void		turn_part1(char **map, char **map2, int pid, int player)
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
  xoxo = my_binary_to_char(receive(pid));
  (xoxo == 'o') ? my_putstr("missed\n\n") : my_putstr("hit\n\n"); //COURS SUR LES TERNAIRES : APPELLE SAHEL
  map2[action[1] - '1'][(action[0] - 'A') * 2] = xoxo;
  turn_part2(map, map2, pid, player);
}
