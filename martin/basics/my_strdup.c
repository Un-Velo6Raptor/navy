/*
** my_strdup.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:48:13 2017 
** Last update Mon Jan 30 15:48:14 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

char	*my_strdup(char *src)
{
  char	*str;

  if ((str = malloc(my_strlen(src) + 1)) == 0)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
