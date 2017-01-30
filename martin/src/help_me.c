/*
** help_me.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Jan 30 16:07:51 2017 
** Last update Mon Jan 30 16:21:57 2017 
*/

#include	"battleship.h"

int		help_me(void)
{
  my_putstr("USAGE\n");
  my_putstr("\t   ./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\t   first_player_pid\tonly for the 2nd player.");
  my_putstr("  pid of the first player,\n");
  my_putstr("\t   navy_positions\tfile representating ");
  my_putstr("the positions of the ships.\n");
  return (0);
}
