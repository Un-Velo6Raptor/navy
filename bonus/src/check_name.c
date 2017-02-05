/*
** check_name.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Feb  3 21:57:12 2017 
** Last update Fri Feb  3 22:12:51 2017 
*/

#include	"my.h"

int		my_char_is_good(char car)
{
  if  ((car >= 'A' && car <= 'Z') ||
       (car >= 'a' && car <= 'z') ||
       (car >= '0' && car <= '9') ||
       car == '_')
    return (0);
  return (84);
}

int		check_namme(char *name)
{
  int		idx;

  idx = 0;
  while (name[idx] != '\0')
    {
      if (my_char_is_good(name[idx]) == 84)
	return (84);
      idx++;
    }
  return (0);
}
