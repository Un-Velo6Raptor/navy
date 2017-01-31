/*
** free_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:46:58 2017 
** Last update Mon Jan 30 15:47:00 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

int		free_tab(char **tab, int nb)
{
  int		idx;

  idx = 0;
  while (tab[idx] != NULL)
    {
      free(tab[idx]);
      idx++;
    }
  free(tab);
  return (nb);
}
