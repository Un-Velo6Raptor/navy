/*
** my_strcmp.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:54:06 2017 
** Last update Mon Jan 30 15:54:07 2017 
*/

#include	"battleship.h"

int	my_strcmp(char *s1, char *s2)
{
  int	idx;

  idx = 0;
  while (s1[idx] == s2[idx])
    {
      idx++;
      if (s1[idx] == '\0' && s2[idx] == '\0')
	return (0);
    }
  if (s1[idx] > s2[idx] && s1[idx] != '\0')
    return (1);
  else
    return (-1);
  return (0);
}
