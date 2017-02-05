/*
** creator_loop.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb  2 12:40:43 2017 
** Last update Sat Feb  4 03:41:26 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	"framefuffer.h"
#include	"my.h"

void		creator_loop(t_my_framebuffer *buffer,
			     t_core_window *ns, char **map,
			     t_mode_background *mode)
{
  sfEvent	event;

  background(buffer, map, mode);
  sfTexture_updateFromPixels(ns->texture, buffer->pixels, WIDTH, HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(ns->window))
    {
      sfRenderWindow_clear(ns->window, sfWhite);
      while (sfRenderWindow_pollEvent(ns->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(ns->window);
	  else if (event.type == sfEvtMouseButtonPressed &&
		   event.mouseButton.button == sfMouseLeft)
	    if (gest_mouse(mode, buffer, &map,
			   create_vector(event.mouseButton.x,
					 event.mouseButton.y)) == 1)
	      sfRenderWindow_close(ns->window);
	  sfTexture_updateFromPixels(ns->texture, buffer->pixels,
				     WIDTH, HEIGHT, 0, 0);
	}
      sfRenderWindow_drawSprite(ns->window, ns->sprite, NULL);
      sfRenderWindow_display(ns->window);
    }
  sfRenderWindow_destroy(ns->window);
}
