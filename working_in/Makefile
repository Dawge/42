# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rostroh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/16 14:27:29 by rostroh           #+#    #+#              #
#    Updated: 2016/12/18 16:54:45 by rostroh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/poney.c \
	  ./src/ft_printf.c \
	  ./src/get_base.c \
	  ./libft/*.c

OBJ = *.o

LIB = libft.a

HEAD = ./incs/ft_printf.h

NAME = libftprintf.a

.PHONY : clean

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
