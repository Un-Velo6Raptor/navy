/*
** free_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:23:54 2017 
** Last update Wed Feb  1 21:26:54 2017 
*/

#include	<stdlib.h>
#include	"my.h"

void		free_tab(char **tab)
{
  int		idx;

  idx = 0;
  while (tab[idx] != NULL)
    {
      free(tab[idx]);
      idx++;
    }
  free(tab);
}
