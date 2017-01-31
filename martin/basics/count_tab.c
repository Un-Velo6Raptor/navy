/*
** count_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 19:57:59 2017 
** Last update Mon Jan 30 19:59:50 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

int		count_tab(char **tab)
{
  int		idx;

  idx = 0;
  while (tab[idx] != NULL)
    idx++;
  return (idx);
}
