/*
** ini_window.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 22:13:46 2017 
** Last update Sat Feb  4 07:54:42 2017 
*/

#include		<stdlib.h>
#include		"my.h"

int			ini_window(char **map, char *name)
{
  t_core_window		needs;
  t_mode_background	mode;
  t_my_framebuffer	*buffer;
  sfEvent		event;
  sfMusic		*music;

  if ((buffer = my_framebuffer_create(700, 409)) == NULL ||
      (needs.window = create_window("Creator_map's navy ", buffer->width,
				    buffer->height)) == NULL)
    return (84);
  sfRenderWindow_pollEvent(needs.window, &event);
  ini_mode(&mode);
  mode.name = name;
  music = start_music("music/background_sound.ogg");
  needs.sprite = sfSprite_create();
  needs.texture = sfTexture_create(buffer->width, buffer->height);
  sfSprite_setTexture(needs.sprite, needs.texture, sfTrue);
  creator_loop(buffer, &needs, map, &mode);
  destroy_music(music, 1);
  return (0);
}
