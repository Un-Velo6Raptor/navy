/*
** background.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb  2 13:17:12 2017 
** Last update Sat Feb  4 05:45:30 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"framefuffer.h"
#include	"my.h"

void		case_ship(t_my_framebuffer *buffer)
{
  int		idx;
  
  idx = 0;
  while (idx < HEIGHT - 10)
    {
      my_draw_line(buffer, create_vector(0 , idx),
		   create_vector(WIDTH - 408, idx), sfBlack);
      idx += HEIGHT / 5;
    }
  my_draw_line(buffer, create_vector((WIDTH - 408) / 2, idx - HEIGHT / 5),
	       create_vector((WIDTH - 408) / 2, HEIGHT), sfBlack);
  my_draw_line(buffer, create_vector(30, 0),
	       create_vector(30, idx - HEIGHT / 5), sfBlack);
}

void		grid(t_my_framebuffer *buffer)
{
  int		idx;

  my_draw_line(buffer, create_vector(WIDTH - 408, 0),
	       create_vector(WIDTH - 408, HEIGHT), sfBlack);
  idx = 0;
  while (idx < HEIGHT)
    {
      my_draw_line(buffer, create_vector(WIDTH - 408, idx),
		   create_vector(WIDTH, idx), sfBlack);
      idx += 51;
    }
  idx = WIDTH - 408;
  while (idx < WIDTH)
    {
      my_draw_line(buffer, create_vector(idx, 0),
		   create_vector(idx, HEIGHT), sfBlack);
      idx += 51;
    }
  case_ship(buffer);
}


void		fill_indic_good(t_my_framebuffer *buffer, sfVector2i from,
				sfVector2i to, sfColor color)
{
  int		save;

  save = from.x;
  while (from.y != to.y)
    {
      from.x = save;
      while (from.x != to.x)
	{
	  my_put_pixel(buffer, from.x, from.y, color);
	  from.x++;
	}
      from.y++;
    }
}

void		indic_good(char **map, t_my_framebuffer *buffer)
{
  fill_indic_good(buffer, create_vector(0, 1), create_vector(30, HEIGHT / 5),
		  (nb_ship_place(map, 2) != 2) ? sfRed : sfGreen);
  fill_indic_good(buffer, create_vector(0, HEIGHT / 5 + 1),
		  create_vector(30, HEIGHT / 5 * 2),
		  (nb_ship_place(map, 3) != 3) ? sfRed : sfGreen);
  fill_indic_good(buffer, create_vector(0, HEIGHT / 5 * 2 + 1),
		  create_vector(30, HEIGHT / 5 * 3),
		  (nb_ship_place(map, 4) != 4) ? sfRed : sfGreen);
  fill_indic_good(buffer, create_vector(0, HEIGHT / 5 * 3 + 1),
		  create_vector(30, HEIGHT / 5 * 4),
		  (nb_ship_place(map, 5) != 5) ? sfRed : sfGreen);
}

void		background(t_my_framebuffer *buffer, char **map,
			   t_mode_background *mode)
{
  (void) map;
  indic_good(map, buffer);
  bouton_display(mode, buffer);
  fill_indic_good(buffer, create_vector((WIDTH - 408) / 2, HEIGHT / 5 * 4 + 1),
		  create_vector((WIDTH - 408), HEIGHT), sfRed);
  if (nb_ship_place(map, 2) == 2 && nb_ship_place(map, 3) == 3 &&
      nb_ship_place(map, 4) == 4 && nb_ship_place(map, 5) == 5)
    fill_indic_good(buffer, create_vector(0, HEIGHT / 5 * 4 + 1),
                    create_vector((WIDTH - 408) / 2, HEIGHT), sfGreen);
  else
    fill_indic_good(buffer, create_vector(0, HEIGHT / 5 * 4 + 1),
                    create_vector((WIDTH - 408) / 2, HEIGHT), sfBlack);
  grid(buffer);
  display_boat(buffer);
}
