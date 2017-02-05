SRCS = sample.c
OBJS = $(SRCS:.c=.o)
LIBS = -L. -lgnl
INCL = -I.
NAME = sample

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) $(LIBS) $(INCL)

all: 	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
