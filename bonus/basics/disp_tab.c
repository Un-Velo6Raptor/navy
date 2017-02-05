/*
** disp_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:21:11 2017 
** Last update Wed Feb  1 22:07:51 2017 
*/

#include	<stdlib.h>
#include	"my.h"

void		disp_map(char **tab)
{
  int		idx;

  idx = 0;
  while (tab[idx] != NULL)
    {
      my_putstr(tab[idx]);
      my_putstr("\n");
      idx++;
    }
}
