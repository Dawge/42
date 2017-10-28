# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rostroh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 14:30:57 by rostroh           #+#    #+#              #
#    Updated: 2017/03/18 18:21:01 by rostroh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  aled.c \
	  hooks.c \
	  draw_call.c \
	  draw_line.c \
	  GNL/get_next_line.c

LIB = libft/libft.a \
	  ft_printf/libftprintf.a

NAME = fdf

FLG = -Wall -Werror -Wextra

FLGMLX = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLGMLX) $(LIB)

clean:
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	make clean -C ./libft
	make clean -C ./ft_printf
	rm -f $(NAME)

re: fclean all
