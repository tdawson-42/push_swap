# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:21:46 by tdawson           #+#    #+#              #
#    Updated: 2022/01/26 20:53:20 by tdawson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC_DIR = srcs
LIB_DIR = srcs/lib
GNL_DIR = srcs/gnl
OBJ_DIR = objs

LIB = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
ft_isprint.c ft_isspace.c ft_isupper.c ft_putchar_fd.c ft_putchar.c \
ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
ft_putstr.c ft_atoi.c ft_tolower.c ft_toupper.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strlen.c ft_strnew.c ft_strjoin.c ft_strlcat.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_itoa.c \
ft_bzero.c ft_memalloc.c ft_memchr.c ft_memdel.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memcmp.c ft_memset.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c \
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strupcase.c ft_strlowcase.c \
ft_str_is_alpha.c ft_str_is_numeric.c ft_str_is_lowercase.c ft_str_is_uppercase.c \
ft_str_is_printable.c ft_itoa_base.c ft_ultoa.c ft_ulltoa.c ft_ftoa.c \
ft_strchr_replace.c ft_strround.c ft_strchr_index.c ft_strchr_swap.c ft_lltoa.c \
ft_ltoa.c ft_strjoinf.c ft_putstrs.c ft_pow.c ft_powl.c ft_numlen.c ft_strccat.c \
ft_strlenc.c ft_min.c ft_max.c ft_numlen_base.c ft_ullmax.c ft_abs.c ft_sum.c

GNL = get_next_line.c

LIB_OBJ = $(addprefix $(OBJ_DIR)/lib/,$(LIB:.c=.o))
GNL_OBJ = $(addprefix $(OBJ_DIR)/gnl/,$(GNL:.c=.o))

INC = ./includes

all: $(NAME)

$(NAME): $(LIB_OBJ) $(GNL_OBJ)
	@ar rcs $(NAME) $^
	
$(OBJ_DIR)/lib/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/lib
	@$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

$(OBJ_DIR)/gnl/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/gnl
	@$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clear fclean re
