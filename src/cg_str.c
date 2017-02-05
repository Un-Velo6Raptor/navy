/*
** cg_str.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Feb  5 18:28:56 2017 
** Last update Sun Feb  5 21:14:28 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

char		*cg_str(char *str)
{
  if (str == NULL)
    return (NULL);
  str = my_good_str(str);
  if (my_strlen(str) != 2)
    return (str);
  if (str[0] < 'A' || str[0] > 'Z')
    my_swap(&str);
  return (str);
}
