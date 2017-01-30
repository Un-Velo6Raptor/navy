/*
** my_putstr.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:43:53 2017 
** Last update Mon Jan 30 15:44:44 2017 
*/

#include	<unistd.h>
#include	"battleship.h"

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
