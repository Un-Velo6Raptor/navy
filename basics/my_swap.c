/*
** my_swap.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Feb  5 15:40:50 2017 
** Last update Sun Feb  5 18:37:14 2017 
*/

#include	<stdlib.h>
#include	"battleship.h"

void		my_swap(char **str)
{
  char		tmp;

  tmp = (*str)[0];
  (*str)[0] = (*str)[1];
  (*str)[1] = tmp;
}

char		*my_good_str(char *str)
{
  char		*new_str;
  int		idx;
  int		idx2;

  idx = 0;
  idx2 = 0;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[idx] != '\0')
    {
      if (str[idx] != ' ' && str[idx] != '\t')
	{
	  new_str[idx2] = (str[idx] >= 'a' &&
			   str[idx] <= 'z') ? (str[idx] - 32) : (str[idx]);
	  idx2++;
	}
      idx++;
    }
  new_str[idx2] = '\0';
  free(str);
  return (new_str);
}
