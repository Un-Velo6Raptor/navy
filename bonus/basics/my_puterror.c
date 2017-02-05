/*
** my_puterror.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 15:44:51 2017 
** Last update Wed Feb  1 21:12:46 2017 
*/

#include	<unistd.h>
#include	"my.h"

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
