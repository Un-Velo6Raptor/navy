/*
** cg_str.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Feb  5 18:28:56 2017 
** Last update Sun Feb  5 18:45:49 2017 
*/

#include	"battleship.h"

char		*cg_str(char *str)
{
  str = my_good_str(str);
  if (my_strlen(str) != 2)
    return (str);
  if (str[0] < 'A' || str[0] > 'Z')
    my_swap(&str);
  return (str);
}
