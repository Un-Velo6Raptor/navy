/*
** my_strcpy.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:47:38 2017 
** Last update Mon Jan 30 15:47:39 2017 
*/

#include	"battleship.h"

char	*my_strcpy(char *dest, char *src)
{
  int	idx;

  idx = 0;
  while (src[idx] != '\0')
    {
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
