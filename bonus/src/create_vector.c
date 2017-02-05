/*
** create_vector.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb  2 13:40:58 2017 
** Last update Thu Feb  2 13:54:30 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"my.h"

sfVector2i	create_vector(int x, int y)
{
  sfVector2i	tmp;

  tmp.x = x;
  tmp.y = y;
  return (tmp);
}
