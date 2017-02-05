/*
** gest_mouse.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb  2 19:40:35 2017 
** Last update Sat Feb  4 07:49:42 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"framefuffer.h"
#include	"my.h"

int		another_mode(t_mode_background *mode, int idx)
{
  if (idx != 2 && mode->ship_2 == 1)
    return (1);
  if (idx != 3 && mode->ship_3 == 1)
    return (1);
  if (idx != 4 && mode->ship_4 == 1)
    return (1);
  if (idx != 5 && mode->ship_5 == 1)
    return (1);
  return (0);
}

void		mouse_bouton(t_mode_background *mode, t_my_framebuffer *buffer,
			     sfVector2i pos)
{
  if (another_mode(mode, 2) == 0 && pos.y < (HEIGHT / 5))
    mode->ship_2 = (mode->ship_2 == 0) ? 1 : 0;
  else if (another_mode(mode, 3) == 0 &&
	   pos.y < (HEIGHT / 5) * 2 && pos.y > (HEIGHT / 5))
    mode->ship_3 = (mode->ship_3 == 0) ? 1 : 0;
  else if (another_mode(mode, 4) == 0 &&
	   pos.y < (HEIGHT / 5) * 3 && pos.y > (HEIGHT / 5) * 2)
    mode->ship_4 = (mode->ship_4 == 0) ? 1 : 0;
  else if (another_mode(mode, 5) == 0 &&
	   pos.y < (HEIGHT / 5) * 4 && pos.y > (HEIGHT / 5) * 3)
    mode->ship_5 = (mode->ship_5 == 0) ? 1 : 0;
}

int		gest_mouse(t_mode_background *mode, t_my_framebuffer *buffer,
			   char ***map, sfVector2i pos)
{
  reset_frame(buffer);
  if (pos.x < WIDTH - 409 && pos.y < (HEIGHT / 5) * 4)
    mouse_bouton(mode, buffer, pos);
  else if (pos.x > WIDTH - 409)
    add_ship(buffer, mode, map, pos);
  else if (pos.x > (WIDTH - 409) / 2 && pos.x < WIDTH - 409)
    return (1);
  else if (nb_ship_place(*map, 2) == 2 && nb_ship_place(*map, 3) == 3 &&
	   nb_ship_place(*map, 4) == 4 && nb_ship_place(*map, 5) == 5)
    {
      create_this_file(mode->name, *map);
      return (1);
    }
  update(*map, buffer);
  background(buffer, *map, mode);
  return (0);
}
