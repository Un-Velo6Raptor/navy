/*
** check_env.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:06:01 2017 
** Last update Wed Feb  1 21:20:42 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		check_name_next(char *str)
{
  if (match(str, "LSCOLORS=*") == 1)
    return (1);
  else if (match(str, "LS_COLORS=*") == 1)
    return (1);
  else if (match(str, "XDG_RUNTIME_DIR=*") == 1)
    return (1);
  return (0);
}

int		check_name(char *str)
{
  if (match(str, "DISPLAY=*") == 1 && str[8] != '\0')
    return (1);
  else if (match(str, "LIBRARY_PATH=*") == 1)
    return (1);
  else if (match(str, "LD_LIBRARY_PATH=*") == 1)
    return (1);
  else if (match(str, "CPATH=*") == 1)
    return (1);
  else if (check_name_next(str) == 1)
    return (1);
  return (0);
}

int		check_env(char **tab)
{
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 0;
  while (tab[idx] != NULL)
    {
      if (check_name(tab[idx]) == 1)
	cpt++;
      idx++;
    }
  if (cpt != 7)
    {
      my_puterror("Bad Env.\n");
      return (1);
    }
  return (0);
}
