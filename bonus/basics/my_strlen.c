/*
** my_strlen.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:20:09 2017 
** Last update Wed Feb  1 21:20:15 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strlen(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
