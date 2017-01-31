/*
** check_coo.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 19:56:49 2017 
** Last update Mon Jan 30 21:00:34 2017 
*/

#include	"battleship.h"

int		is_a_good_char(char car)
{
  if (car < 'A' || car > 'H')
    return (84);
  return (0);
}

int		char_num(char car)
{
  if (car >= '1' && car <= '8')
    return (0);
  return (84);
}

int		diff_two_car(char car1, char car2, char opt)
{
  int		result;

  if (opt == 'A' && (is_a_good_char(car1) != 0 || is_a_good_char(car2) != 0))
    return (-1);
  if (opt == '0' && (char_num(car1) != 0 || char_num(car2) != 0))
    return (-1);
  if ((car2 - opt) > 8 || (car1 - opt) > 8)
    return (-1);
  result = (car1 - opt) - (car2 - opt);
  if (result < 0)
    result *= -1;
  return (result + 1);
}

int		check_coo(int size, char *s1, char *s2)
{
  if (my_strlen(s1) != 2 || my_strlen(s2) != 2 || size < 2 || size > 5)
    return (84);
  if ((s1[0] != s2[0]) && (s1[1] == s2[1]))
    return ((diff_two_car(s1[0], s2[0], 'A') != size) ? (84) : (0));
  if ((s1[0] == s2[0]) && (s1[1] != s2[1]))
    return ((diff_two_car(s1[1], s2[1], '0') != size) ? (84) : (0));
  return (84);
}
