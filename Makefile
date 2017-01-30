##
## Makefile for  in /home/sahel/rendu/PSU/PSU_2016_navy
## 
## Made by Sahel
## Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
## 
## Started on  Mon Jan 30 14:28:05 2017 Sahel
## Last update Mon Jan 30 18:50:53 2017 Sahel
##

SRC	=	core.c	\
		game.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g

NAME	=	navy

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
