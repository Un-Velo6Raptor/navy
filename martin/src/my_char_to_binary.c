/*
** my_char_to_binary.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 14:16:30 2017 
** Last update Mon Jan 30 15:14:32 2017 
*/

#include	<stdlib.h>
#include	<stdio.h>

int		my_power_rec(int nb, int p)
{
  int		idx;

  if (nb < 0)
    nb *= -1;
  if (p == 0)
    return (1);
  if (p < 0)
    return (0);
  idx = nb;
  if (p > 0)
    {
      idx *= my_power_rec(nb, p - 1);
      if ((nb < 0) && (p % 2 == 1))
        return (-1 * idx);
    }
  return (idx);
}

char		my_binary_to_char(char *str)
{
  int		result;
  int		idx;

  result = 0;
  idx = 7;
  while (idx >= 0)
    {
      if (str[idx] != '0')
	result += 1 * my_power_rec(2, idx);
      idx--;
    }
  return (result);
}

char		*my_char_to_binary(char car)
{
  char		*str;
  int		idx;

  idx = 0;
  if ((str = malloc(sizeof(char) * 9)) == NULL)
    return (NULL);
  while (idx < 8)
    {
      str[idx] = (car & 1) + '0';
      car >>= 1;
      idx++;
    }
  str[idx] = '\0';
  return (str);
}
