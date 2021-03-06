##
## Makefile for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Mon Jan 30 15:37:45 2017 
## Last update Fri Feb 17 11:10:34 2017 
##

SRC	=	src/main.c			\
		src/help_me.c			\
		src/ini_map.c			\
		src/disp_map.c			\
		src/check_coo.c			\
		src/my_char_to_binary.c		\
		src/core.c			\
		src/send_receive.c		\
		src/connect.c			\
		src/game.c			\
		src/cg_str.c			\
		src/check_all_ship.c		\
		src/win_loose.c

BASICS	=	basics/my_putstr.c		\
		basics/my_put_nbr.c		\
		basics/my_puterror.c		\
		basics/free_tab.c		\
		basics/my_strcpy.c		\
		basics/my_strdup.c		\
		basics/my_strlen.c		\
		basics/my_path_tab.c		\
		basics/my_getnbr.c		\
		basics/my_char_isnum.c		\
		basics/count_tab.c		\
		basics/my_swap.c		\
		basics/my_strcmp.c

OBJ	=	$(SRC:.c=.o)			\
		$(BASICS:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

NAME	=	navy

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -L. -lgnl

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
