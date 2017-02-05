/*
** my_strcat.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Feb  3 22:18:51 2017 
** Last update Fri Feb  3 22:19:13 2017 
*/

#include	"my.h"

char		*my_strcat(char *dest, char *src)
{
  int		dest_len;
  int		i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
