/*
** my.h for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:08:01 2017 
** Last update Sun Feb  5 22:53:58 2017 
*/

#ifndef MY_H_
# define MY_H_

# include	<SFML/Graphics/RenderWindow.h>
# include	<SFML/Graphics/Texture.h>
# include	<SFML/Graphics/Sprite.h>
# include	<SFML/Graphics/Color.h>
# include	<SFML/Audio.h>
# include	"framefuffer.h"

typedef struct		s_core_window
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_core_window;

typedef struct		s_mode_background
{
  char			*name;
  int			ship_2;
  int			ship_3;
  int			ship_4;
  int			ship_5;
}			t_mode_background;

# define        HEIGHT  buffer->height
# define        WIDTH   buffer->width

/*
**	Prototypes of file's src.
*/

void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfRenderWindow		*create_window(char *, int, int);
int			ini_window(char **, char *);
t_my_framebuffer	*my_framebuffer_create(int, int);
int			help_me(void);
char			**create_map(void);
void			creator_loop(t_my_framebuffer *, t_core_window *,
				     char **, t_mode_background *);
void			background(t_my_framebuffer *, char **,
				   t_mode_background *);
void			my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);
sfVector2i		create_vector(int, int);
void			reset_frame(t_my_framebuffer *);
void			ini_mode(t_mode_background *);
void			bouton_display(t_mode_background *,
				       t_my_framebuffer *);
int			gest_mouse(t_mode_background *, t_my_framebuffer *,
				   char ***, sfVector2i);
int			add_ship(t_my_framebuffer *, t_mode_background *,
				 char ***, sfVector2i);
int			check_the_ship(int, char ***, sfVector2i,
				       t_my_framebuffer *);
int			cross(char **, int, sfVector2i);
void			update(char **, t_my_framebuffer *);
sfColor			color_bouton(sfVector2i);
int			nb_ship_place(char **, int);
sfColor			set_pixel_color(int, int, int);
void			fill_indic_good(t_my_framebuffer *, sfVector2i,
					sfVector2i, sfColor);
int			create_this_file(char *, char **);
int			check_namme(char *);
sfMusic			*start_music(char *);
int			destroy_music(sfMusic *, int);
void			display_boat(t_my_framebuffer *);

/*
**	Prototypes of file's basics.
*/

void			disp_map(char **);
void			free_tab(char **);
void			my_putstr(char *);
void			my_puterror(char *);
int			my_strlen(char *);
int			match(char *, char *);
char			*my_strcpy(char *, char *);
char			*my_strdup(char *);
int			my_strcmp(char *, char *);
void			disp_map(char **);
char			*my_strcat(char *, char *);

#endif /* !MY_H_ */
