/*
** game.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 30 17:24:11 2017 Sahel
** Last update Mon Jan 30 18:50:25 2017 Sahel
*/

int	is_valid(char *str)
{
  return (1);
}

int	start(int signal)
{
  (void) signal;
}

char	check_xo(char **map, char *action)
{
  char	map_char;

  map_char = map[action[0] - 'A'][action[1] - '0'];
  if (map_char == '.' || map_char == 'o')
    return ('o');
  return ('x');
}

int	turn_part2(char **map, char **map2, int pid)
{
  char	action[3];
  char	xoxo;

  signal(SIGUSR1, start);
  sleep(3600);
  action[0] = my_binary_to_char(receive(pid));
  action[1] = my_binary_to_char(receive(pid));
  action[2] = '/0';
  xoxo = check_xo(map, action);
  map[action[0] - 'A'][action[1] - '0'] = xoxo;
  send(pid, my_char_to_binary(xoxo));
  turn_part1(map, map2, pid);
}

int	turn_part1(char **map, char **map2, int pid)
{
  char	*action;
  char	xoxo;

  while (!is_valid(action = get_next_line(0)));
  kill(pid, SIGUSR1);
  send(pid, my_char_to_binary(action[0]));
  send(pid, my_char_to_binary(action[1]));
  xoxo = my_binary_to_char(receive(pid));
  map[action[0] - 'A'][action[1] - '0'] = xoxo;
  turn_part2(map, map2, pid);
}
