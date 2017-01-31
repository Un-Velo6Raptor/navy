/*
** my_put_nbr.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Jan 31 21:54:21 2017 
** Last update Tue Jan 31 21:58:04 2017 
*/

#include	<unistd.h>
#include	"battleship.h"

void		my_put_nbr(int nb)
{
  int		idx;
  long int	nb1;

  nb1 = nb;
  idx = 1;
  if (nb1 < 0)
    {
      my_putchar('-');
      nb1 = nb1 * -1;
    }
  while ((nb1 / idx) >= 10)
    idx = idx * 10;
  while (idx > 0)
    {
      my_putchar((nb1 / idx) % 10 + 48);
      idx = idx / 10;
    }
}
