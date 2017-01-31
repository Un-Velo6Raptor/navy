/*
** is_valid.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Jan 31 16:51:40 2017 
** Last update Tue Jan 31 16:57:22 2017 
*/

#include	"battleship.h"

int		is_valid(char *str)
{
  if (my_strlen(str) != 2)
    return (84);
  if ((str[0] >= 'A' && str[0] <= 'H') &&
      (str[1] >= '1' && str[1] <= '8'))
    return (0);
  return (84);
}
