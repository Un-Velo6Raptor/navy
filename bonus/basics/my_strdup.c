/*
** my_strdup.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:19:57 2017 
** Last update Wed Feb  1 21:20:02 2017 
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_strdup(char *src)
{
  char	*str;

  if ((str = malloc(my_strlen(src) + 1)) == 0)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
