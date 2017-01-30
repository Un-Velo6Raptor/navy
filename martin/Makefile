##
## Makefile for  in /home/januar_m/delivery/PSU/PSU_2016_navy/martin
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Mon Jan 30 15:37:45 2017 
## Last update Mon Jan 30 19:52:02 2017 
##

SRC	=	src/main.c			\
		src/help_me.c			\
		src/ini_map.c			\
		src/disp_map.c			\
		src/my_char_to_binary.c

BASICS	=	basics/my_putstr.c		\
		basics/my_puterror.c		\
		basics/free_tab.c		\
		basics/my_strcpy.c		\
		basics/my_strdup.c		\
		basics/my_strlen.c		\
		basics/my_path_tab.c		\
		basics/my_getnbr.c		\
		basics/my_strcmp.c

GNL	=	gnl/get_next_line.c

OBJ	=	$(SRC:.c=.o)			\
		$(BASICS:.c=.o)			\
		$(GNL:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include/

NAME	=	navy

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
