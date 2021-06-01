SRCS = main.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
LIBS = -lpthread

EXEC = philo_one

all:	$(NAME)

$(NAME):
	gcc -g3 $(FLAGS) $(SRCS) -o $(EXEC) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re: fclean all
