# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabounak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 10:02:19 by aabounak          #+#    #+#              #
#    Updated: 2021/06/03 10:02:19 by aabounak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = 

LIBNAME = utils_lib.a

NAME = philo_one

EXEC = philo_one

SRCS = main.c

LIBS = -lpthread

all: $(NAME)

$(LIBNAME): $(SRC)
	make -C utils/
	cp utils/$(LIBNAME) ./

$(NAME): $(LIBNAME)
	@echo "Compilation in progress! DO NOT INTERRUPT!"
	gcc -g3 $(FLAGS) $(SRCS) utils_lib.a -o $(EXEC) $(LIBS)
	@echo "Compilation done! :)"

clean:
	make clean -C utils/
	rm -f *.o

fclean: clean
	make fclean -C utils/
	rm -f *.a
	rm -f $(EXEC)
	rm -rf $(EXEC).dSYM
	rm -rf .vscode

re: fclean all
