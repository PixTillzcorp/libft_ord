# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 12:59:15 by heinfalt          #+#    #+#              #
#    Updated: 2016/12/05 12:47:28 by heinfalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PHONY allow rules to be done even w/ files w/ the same name in the dir.

.PHONY: clean, fclean, re, all

.SUFFIXES:

#~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~

FONT_NOIR = \033[40m
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m
GREY = \033[37m

NORMAL = \033[0m

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NAME = fdf

VPATH = libft/objfiles

LIB_PATH = libft/

SRCC =	fdf.c ft_calc.c ft_draw.c ft_check.c ft_error.c ft_hook.c ft_legend.c \
		ft_map.c ft_move.c ft_quit.c ft_window.c ft_zoom.c

SRCO =	$(SRCC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#~~~~~~~~~~~~~MINILIBX~~~~~~~~~~~~~~

MLX = ./minilibx/
MLX_LIB = $(addprefix $(MLX),libmlx.a))
MLX_LNK = -L ./minilibx -l mlx -framework OpenGl -framework AppKit

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

all: lib $(MLX_LIB) $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

lib:
	make -C ./libft

$(MLX_LIB):
	make -C $(MLX)

$(NAME) : $(SRCO)
	$(CC) -o $(NAME) $(SRCO) $(MLX_LNK) $(LIB_PATH)libft.a
	
clean:
	rm -f $(SRCO)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean
	

re: fclean all
