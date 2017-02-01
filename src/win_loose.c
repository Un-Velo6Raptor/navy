/*
** win_loose.c for  in /home/sahel/rendu/PSU/PSU_2016_navy
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Wed Feb  1 12:28:32 2017 Sahel
** Last update Wed Feb  1 12:33:08 2017 Sahel
*/

static int	win(char **map)
{
  int		map_i;
  int		x_count;
  int		str_i;

  map_i = 0;
  x_count = 0;
  while (map[map_i])
    {
      str_i = 0;
      while (map[map_i][str_i])
	{
	  if (map[map_i][str_i] == 'x')
	    x_count++;
	  str_i++;
	}
      map_i++;
    }
  if (x_count == 14)
    return (1);
  return (0);
}

int	win_loose(char **map, char **map2)
{
  if (win(map))
    return (2);
  if (win(map2))
    return (1);
  return (0);
}
