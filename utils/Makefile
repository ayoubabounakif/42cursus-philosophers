# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabounak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 09:59:46 by aabounak          #+#    #+#              #
#    Updated: 2021/06/03 09:59:46 by aabounak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utils_lib.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar_fd.c ft_putstr_fd.c \
ft_strlen.c \
ft_atoi.c \
ft_exit.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
