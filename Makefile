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

.PHONY: clean, fclean, re, open, reset, all, cleared

# ********************************* DISPLAY ********************************** #

SRC_NBR = $(words $(SRCO))

PRCENT = $(shell echo \($(DONE) \* 100\) \/ $(SRC_NBR) | bc)

REST = $(shell echo \($(DONE) \* 100\) \% $(SRC_NBR) | bc)

PRGRSS = $(shell echo \($(PRCENT) \/ 2\) + 1 | bc)

DONE = 0

BAR = $(shell echo "\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#" | cut -c 1-$(PRGRSS))

EMPTY = $(shell echo "                                                  " | cut -c $(PRGRSS)-50)

# **************************************************************************** #

#~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~

BLACK = \033[38;5;0m
RED = \033[38;5;196m
GREEN = \033[38;5;46m
YELLOW = \033[38;5;226m
ORANGE = \033[38;5;202m
BLUE = \033[38;5;18m
PINK = \033[38;5;207m
PURPLE = \033[38;5;57m
CYAN = \033[38;5;45m
GREY = \033[38;5;242m
NORMAL = \033[0m

#Includes

INC = includes/

HEADERS = libft.h ft_printf.h commandline.h get_next_line.h ft_bin.h

#Name of the build (here a lib)

NAME = libft.a

#Compiler

CC = gcc

#Path of the location of every .c files

VPATH = ft_is:		\
		ft_mem:		\
		ft_put:		\
		ft_str:		\
		ft_lst:		\
		conv:		\
		other:		\
		ft_printf:	\
		ft_env:		\
		ft_input:	\
		ft_bin

#Path of the location of every .o files

OBJDIR = objfiles

#Objs will be the fills we need to create to do the lib

SRCO_MEM =	ft_bzero.o ft_memcpy.o ft_memchr.o ft_memcmp.o ft_memset.o		\
			ft_memdel.o ft_memccpy.o ft_memmove.o ft_memalloc.o				\
			ft_memrealloc.o

SRCO_STR =	ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o ft_strchr.o		\
			ft_strstr.o ft_strcmp.o ft_strrev.o ft_strnew.o ft_strdel.o		\
			ft_strclr.o ft_strmap.o ft_strequ.o ft_strsub.o ft_strncat.o	\
			ft_strlcat.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strrchr.o\
			ft_strnstr.o ft_strncmp.o ft_striter.o ft_strmapi.o ft_strnequ.o\
			ft_strjoin.o ft_strtrim.o ft_striteri.o ft_strsplit.o			\
			ft_chrjoin_free.o ft_strjoin_free.o ft_strdup_free.o			\
			ft_strchange.o ft_strchain.o ft_strstart.o ft_strclr_split.o	\
			ft_strnchr.o ft_strrmv.o ft_strndup.o ft_strrand.o

SRCO_IS =	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
			ft_is_wstring.o ft_is_white_space.o	ft_is_wchar.o ft_ishexa.o

SRCO_PUT =	ft_putstr.o ft_putnbr.o ft_putlnbr.o ft_putwstr.o ft_putendl.o	\
			ft_putchar.o ft_putnstr.o ft_putwchar.o ft_putxchar.o			\
			ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_putchar_fd.o	\
			ft_ret_putchar.o ft_putstr_free.o ft_putstr_clrd.o ft_putfile.o	\
			ft_putstrs.o

SRCO_LST =	ft_lstnew.o ft_lstdel.o ft_lstadd.o ft_lstmap.o ft_lstiter.o	\
			ft_lstappend.o ft_lstdelone.o ft_lst_push_back.o ft_lstlen.o	\
			ft_lstdel_f.o ft_lstdel_n.o ft_lstfree.o ft_lstinsert.o			\
			ft_lstcpy.o ft_lstjoin.o ft_lst_strsplit.o ft_lstdel_x.o		\
			ft_lstdel_str.o ft_lstvnsh.o ft_lstsnipe.o

SRCO_CONV =	ft_itoa.o ft_atoi.o ft_litoa.o ft_dbltoa.o ft_ulitoa.o			\
			ft_initmod.o ft_initlmod.o ft_bin_to_dec.o ft_dec_to_bin.o		\
			ft_dec_to_hex.o ft_dec_to_sci.o ft_hex_to_dec.o ft_ptr_to_hex.o	\
			ft_dec_to_base.o ft_ldec_to_bin.o ft_ldec_to_hex.o				\
			ft_ldec_to_base.o ft_lst_to_str.o ft_char_to_str.o				\
			ft_lst_to_tab.o ft_lst_to_strcat.o ft_str_to_hex.o				\
			ft_hex_to_str.o

SRCO_OTHR =	ft_charswap.o ft_pow.o ft_swap.o ft_wstrlen.o ft_wcharlen.o		\
			ft_ret_free.o ft_nbrlen.o ft_retstr_free.o ft_swap_chr.o		\
			get_next_line.o ft_retvoid_free.o ft_data_type.o ft_newpath.o	\
			ft_give_pwd.o ft_free_tab.o ft_ret_freetab.o ft_unbrlen.o		\
			ft_check_dir.o ft_check_file.o ft_file_get.o ft_power.o

SRCO_PRINTF =	check_wsc.o flag.o flag_flag.o ft_printf.o lenmod.o			\
				operation.o operation_2.o other.o

SRCO_INPUT =	ft_input.o cursor.o insert_delete.o term.o

SRCO_BIN =	ft_bin_addflag.o ft_bin_decoct.o ft_bin_incoct.o ft_bin_intoct.o\
			ft_bin_rplcoct.o ft_bin_shownbr.o ft_bin_showoct.o				\
			ft_bin_valoct.o ft_bin_chkflag.o ft_bin_incnbr.o

SRCO_ENV =	ft_env.o ft_envclone.o ft_env_val.o ft_env_give.o

SRCO = $(addprefix $(OBJDIR)/,	$(SRCO_MEM)\
								$(SRCO_STR)\
								$(SRCO_PUT)\
								$(SRCO_LST)\
								$(SRCO_IS)\
								$(SRCO_CONV)\
								$(SRCO_OTHR)\
								$(SRCO_INPUT)\
								$(SRCO_BIN)\
								$(SRCO_PRINTF)\
								$(SRCO_ENV))

SRCC = $(SRCO:.o=.c)

#Compiler flags

CFLAGS = -Wall -Wextra -Werror

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				   RULES
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Master rule : "One Rule to rule them all !!"

all: $(NAME)

#Those ones display colored infos

reset_init:
	@ echo "$(YELLOW)~ Reset $(NAME) ~$(NORMAL)"

reset_cmpl:
	@ echo "$(GREEN)~ Reset $(NAME) Complete ~$(NORMAL)"

cleared:
	@ echo "$(RED)~ Clean $(NAME) ~$(NORMAL)"

full_clean:
	@ echo "$(RED)~ Full Clean $(NAME) ~$(NORMAL)"

#Those rules create .o from .c if the obj is older than the src or doesnt exists

$(OBJDIR)/%.o: %.c
	@ $(eval DONE = $(shell echo $(DONE) + 1 | bc ))
	@ echo "\r \b$(PURPLE)[$(NORMAL)$(BAR)$(EMPTY)$(PURPLE)] {$(NORMAL)$(PRCENT).$(REST)$(PURPLE)} $(NORMAL)\t\c"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/
	
#This one build the lib

$(NAME): $(SRCO)
	@ echo "$(PURPLE)[$(GREEN)\xe2\x9c\x94$(PURPLE)] $(NAME)$(NORMAL)"
	@ ar rc $(NAME) $^ && ranlib $(NAME)

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				  CLEANING
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------


#Cleaning obj files

clean: cleared
	@ rm -f $(SRCO)

#Cleaning obj files and the lib

fclean: full_clean
	@ rm -f $(SRCO)
	@ rm -f $(NAME)

#Reset the compil : "Cleaning to rebuild everything better"

re: reset_init fclean all reset_cmpl
