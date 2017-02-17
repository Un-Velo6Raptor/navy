/*
** check_all_ship.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 13 11:16:12 2017 
** Last update Mon Feb 13 11:32:05 2017 
*/

#include	<stdio.h>
#include	"battleship.h"

int		check_all_ship(int **all_ship)
{
  int		idx;

  idx = 0;
  while (idx < 4)
    {
      if ((*all_ship)[idx] != 0)
	return (84);
      idx++;
    }
  return (0);
}
