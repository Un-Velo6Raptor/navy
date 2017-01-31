/*
** ini_gnl.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Jan 31 13:52:47 2017 
** Last update Tue Jan 31 14:00:23 2017 
*/

#include	<stdlib.h>
#include	"get_next_line.h"

void		ini_gnl(t_buffer *news)
{
  (*news).idx = 0;
  (*news).cpt = 0;
  (*news).size = 0;
  (*news).buffer[0] = '\0';
}
