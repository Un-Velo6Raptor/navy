/*
** my_strcpy.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:19:46 2017 
** Last update Wed Feb  1 21:20:55 2017 
*/

#include	"my.h"

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
