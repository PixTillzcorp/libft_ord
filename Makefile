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

.PHONY: clean, fclean, re

#Name of the build (here a lib)

NAME = libft.a

#Compiler

CC = gcc

#Paths are the location of every .c files

PATH_IS = ft_is/

PATH_MEM = ft_mem/

PATH_STR = ft_str/

PATH_LST = ft_lst/

PATH_CONV = conv/

PATH_OTHR = other/

#Objs will be the fills we need to create to do the lib

SRCO_MEM =	ft_bzero.o ft_memcpy.o ft_memchr.o ft_memcmp.o ft_memset.o		\
			ft_memdel.o ft_memccpy.o ft_memmove.o ft_memalloc.o				\

SRCC_MEM = $(SRCO_MEM:.o=.c)

SRCO_STR =	ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o ft_strchr.o		\
			ft_strstr.o ft_strcmp.o ft_strrev.o ft_strnew.o ft_strdel.o		\
			ft_strclr.o ft_strmap.o ft_strequ.o ft_strsub.o ft_strncat.o	\
			ft_strlcat.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strrchr.o\
			ft_strnstr.o ft_strncmp.o ft_striter.o ft_strmapi.o ft_strnequ.o\
			ft_strjoin.o ft_strtrim.o ft_striteri.o ft_strsplit.o			\
			ft_chrjoin_free.o ft_strjoin_free.o								\

SRCC_STR = $(SRCO_STR:.o=.c)

SRCO_IS =	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
			ft_is_wstring.o ft_is_white_space.o								\

SRCC_IS = $(SRCO_IS:.o=.c)

SRCO_PUT =	ft_putstr.o ft_putnbr.o ft_putlnbr.o ft_putwstr.o ft_putendl.o	\
			ft_putchar.o ft_putnstr.o ft_putwchar.o ft_putxchar.o			\
			ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_putchar_fd.o	\

SRCC_PUT = $(SRCO_PUT:.o=.c)

SRCO_LST =	ft_lstnew.o ft_lstdel.o ft_lstadd.o ft_lstmap.o ft_lstiter.o	\
			ft_lstappend.o ft_lstdelone.o									\

SRCC_LST = $(SRCO_LST:.o=.c)

SRCO_CONV =	ft_itoa.o ft_atoi.o ft_litoa.o ft_dbltoa.o ft_ulitoa.o			\
			ft_initmod.o ft_initlmod.o ft_bin_to_dec.o ft_dec_to_bin.o		\
			ft_dec_to_hex.o ft_dec_to_sci.o ft_hex_to_dec.o ft_ptr_to_hex.o	\
			ft_dec_to_base.o ft_ldec_to_bin.o ft_ldec_to_hex.o				\
			ft_ldec_to_base.o												\

SRCC_CONV = $(SRCO_CONV:.o=.c)

SRCO_OTHR =	ft_charswap.o ft_pow.o ft_swap.o ft_wstrlen.o					\

SRCC_OTHR = $(SRCO_OTHR:.o=.c)

#Compiler flags

CFLAGS = -Wall -Wextra -Werror

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				   RULES
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Master rule : "One Rule to rule them all !!"

all: $(NAME)

#Those rules creats .o from .c if the obj is older than the src

%.o: $(PATH_IS)%.c
	$(CC) $(CFLAGS) -c $^

%.o: $(PATH_MEM)%.c
	$(CC) $(CFLAGS) -c $^

%.o: $(PATH_STR)%.c
	$(CC) $(CFLAGS) -c $^

%.o: $(PATH_LST)%.c
	$(CC) $(CFLAGS) -c $^

%.o: $(PATH_PUT)%.c
	$(CC) $(CFLAGS) -c $^

%.o: $(PATH_CONV)%.c
	$(CC) $(CFLAGS) -c $^

%.o: $(PATH_OTHR)%.c
	$(CC) $(CFLAGS) -c $^

#This one build the lib

$(NAME): $(SRCO_MEM) $(SRCO_STR) $(SRCO_LST) $(SRCO_IS) $(SRCO_CONV) $(SRCO_OTHR)
	ar rc $(NAME) $^ && ranlib $(NAME)

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				  CLEANING
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Cleaning obj files

clean:
	rm -f $(SRCO_MEM) $(SRCO_STR) $(SRCO_LST) $(SRCO_IS) $(SRCO_CONV) $(SRCO_OTHR)

#Cleaning obj files and the lib

fclean: clean
	rm -f $(NAME)

#Reset the compil : "Cleaning to rebuild everything better"

re: fclean all
