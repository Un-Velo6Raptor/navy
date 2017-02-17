/*
** game.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 17:24:11 2017 Sahel
** Last update Fri Feb 17 11:31:48 2017 Sahel
*/

#include	<signal.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"battleship.h"
#include	"gnl.h"

extern t_glob	*g_glob;

int		is_valid(char *str)
{
  if (str == NULL)
    return (0);
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

char	check_xo(char **map, char *action)
{
  char	map_char;

  map_char = map[action[1] - '1'][(action[0] - 'A') * 2];
  if (map_char == 'x')
    return ('z');
  if (map_char == '.' || map_char == 'o')
    return ('o');
  return ('x');
}

struct sigaction	init_sa(void)
{
  struct sigaction	sact;

  sact.sa_sigaction = &get_enemy_id;
  sact.sa_flags = SA_SIGINFO;
  sigemptyset(&sact.sa_mask);
  return (sact);
}

int	turn_part2(char **map, char **map2, int pid, int player)
{
  struct sigaction sact;
  char	action[3];
  char	xoxo;
  int	ret;

  if (player == 2)
    disp_my_and_enemy_map(map, map2);
  my_putstr("waiting for enemy's attack...\n");
  sact = init_sa();
  sigaction(SIGUSR1, &sact, NULL);
  pause();
  if (g_glob->pid != g_glob->last_pid ||
      (action[0] = my_binary_to_char(receive(pid))) == '\0' ||
      (action[1] = my_binary_to_char(receive(pid))) == '\0')
    return (84);
  write(1, action, 2);
  xoxo = check_xo(map, action);
  my_putstr((xoxo == 'o' || xoxo == 'z') ? ": missed\n\n" : ": hit\n\n");
  map[action[1] - '1'][(action[0] - 'A') * 2] = (xoxo == 'z') ? 'x' : xoxo;
  usleep(10000);
  send(pid, my_char_to_binary(xoxo));
  ret = win_loose(map, map2);
  return ((ret) ? ((ret == 1) ? (0) : (1)) :
	  (turn_part1(map, map2, pid, player)));
}

int		turn_part1(char **map, char **map2, int pid, int player)
{
  char		*action;
  char		xoxo;
  int		ret;

  if (player == 1)
    disp_my_and_enemy_map(map, map2);
  my_putstr("attack: ");
  while (!is_valid(action = cg_str(get_next_line(0))));
  my_putstr(action);
  my_putstr(": ");
  usleep(5000);
  kill(pid, SIGUSR1);
  usleep(30000);
  send(pid, my_char_to_binary(action[0]));
  send(pid, my_char_to_binary(action[1]));
  if ((xoxo = my_binary_to_char(receive(pid))) == '\0')
    return (84);
  my_putstr((xoxo == 'o' || xoxo == 'z') ? "missed\n\n" : "hit\n\n");
  map2[action[1] - '1'][(action[0] - 'A') * 2] = (xoxo == 'z') ? 'x' : xoxo;
  ret = win_loose(map, map2);
  free(action);
  return ((ret) ? ((ret == 1) ? (0) : (1)) :
	  (turn_part2(map, map2, pid, player)));
}
