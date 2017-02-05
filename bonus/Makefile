##
## Makefile for  in /home/januar_m/delivery/graphical/bswireframe
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Thu Dec  8 13:59:46 2016 
## Last update Sat Feb  4 05:45:47 2017 
##

SRC	=	src/main.c			\
		src/my_draw_line.c		\
		src/creator_loop.c		\
		src/ini_window.c		\
		src/my_put_pixel.c		\
		src/reset_frame.c		\
		src/create_window.c		\
		src/set_pixel_color.c		\
		src/help_me.c			\
		src/create_map.c		\
		src/background.c		\
		src/ini_mode.c			\
		src/create_vector.c		\
		src/bouton_display.c		\
		src/gest_mouse.c		\
		src/add_ship.c			\
		src/check_the_ship.c		\
		src/update.c			\
		src/create_this_file.c		\
		src/check_name.c		\
		src/music.c			\
		src/display_boat.c		\
		src/my_framebuffer_create.c

BASICS	=	basics/my_strdup.c		\
		basics/check_env.c		\
		basics/my_strcmp.c		\
		basics/my_putstr.c		\
		basics/match.c			\
		basics/free_tab.c		\
		basics/my_strcpy.c		\
		basics/my_strlen.c		\
		basics/disp_tab.c		\
		basics/my_strcat.c		\
		basics/my_puterror.c

OBJ	=	$(SRC:.c=.o)			\
		$(BASICS:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include/

NAME	=	map_creator

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
