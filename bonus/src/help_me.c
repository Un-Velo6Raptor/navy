/*
** help_me.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:47:30 2017 
** Last update Wed Feb  8 12:54:26 2017 
*/

#include	"my.h"

int		help_me(void)
{
  my_putstr("USAGE\n\t\t./map_creator \"name_of_new_map\"\n");
  my_putstr("\t\t\\___________/\t\t\\---> Only alpha_numeric and \'_\'.\n");
  my_putstr("\t\t  \\_/\n");
  my_putstr("\t\t   |-->\tOrange for a boat of lenght two\n");
  my_putstr("\t\t   |-->\tPink for a boat of lenght three\n");
  my_putstr("\t\t   |-->\tGreen for a boat of lenght four\n");
  my_putstr("\t\t   |-->\tBlue for a boat of lenght five\n\n");
  my_putstr("\t /!\\ You need to create a directory named map_create\n");
  my_putstr("\n\t\t-h\tLook this Help\n\nBy martin.januario@epitech.eu");
  my_putstr(" and Sahel Lucas Saoudi\n");
  return (0);
}
