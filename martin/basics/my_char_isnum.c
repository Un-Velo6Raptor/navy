/*
** my_char_isnum.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 19:53:32 2017 
** Last update Mon Jan 30 19:55:14 2017 
*/

#include	"battleship.h"

int		my_char_isnum(char car)
{
  if (car >= '0' && car <= '9')
    return (0);
  return (1);
}
