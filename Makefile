# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 15:18:59 by mchi              #+#    #+#              #
#    Updated: 2019/03/30 16:58:50 by mchi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

SRCDIR=./src/

SRC=fractol.c img.c init.c complex.c julia.c multibrot.c expose.c key_press.c loop.c \
thread_pool.c mouse.c color.c

SRCALL=$(addprefix $(SRCDIR), $(SRC))

LIB=-lmlx -lm -lft -L./libft -L./minilibx_macos -framework OpenGL -framework AppKit
INC=-Iinclude -Ilibft -Iminilibx_macos
FLAG=-Wall -Werror -Wextra -g

LIBFT=./libft/libft.a

MINILIBX=./minilibx_macos/libmlx.a
 
OBJ=fractol.o img.o init.o complex.o julia.o multibrot.o expose.o key_press.o loop.o \
thread_pool.o mouse.o color.o

NAME=fractol

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) $(FLAG) -c $(INC) $(SRCALL)
	$(CC) $(FLAG) $(LIB) $(INC) $(OBJ) -o $(NAME)

$(LIBFT):
#	make -C libft

$(MINILIBX):
#	make -C minilibx_macos

clean:
#	make -C libft clean
#	make -C minilibx_macos clean
	rm -rf $(OBJ)

fclean: clean
#	rm -f $(MINILIBX)
#	rm -f $(LIBFT)
	rm -f $(NAME)

re:
	make fclean
	make all
