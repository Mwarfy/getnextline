# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matranch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 17:08:16 by matranch          #+#    #+#              #
#    Updated: 2018/08/14 00:10:16 by matranch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror

SRC= ft_memset.c\
	 ft_bzero.c\
	 ft_memcpy.c\
	 ft_memccpy.c\
	 ft_memmove.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_strlen.c\
	 ft_strdup.c\
	 ft_strcpy.c\
	 ft_strncpy.c\
	 ft_strcat.c\
	 ft_strncat.c\
	 ft_strlcat.c\
	 ft_strchr.c\
	 ft_strrchr.c\
	 ft_strstr.c\
	 ft_strnstr.c\
	 ft_strcmp.c\
	 ft_strncmp.c\
	 ft_atoi.c\
	 ft_isalpha.c\
	 ft_isdigit.c\
	 ft_isalnum.c\
	 ft_isascii.c\
	 ft_isprint.c\
	 ft_toupper.c\
	 ft_tolower.c\
	 ft_memalloc.c\
	 ft_memdel.c\
	 ft_strnew.c\
	 ft_strdel.c\
	 ft_strclr.c\
	 ft_putchar.c\
	 ft_putstr.c\
	 ft_putendl.c\
	 ft_putnbr.c\
	 ft_striter.c\
	 ft_striteri.c\
	 ft_strmap.c\
	 ft_strmapi.c\
	 ft_strequ.c\
	 ft_strnequ.c\
	 ft_strsub.c\
	 ft_strjoin.c\
	 ft_strjoinfree.c\
	 ft_strtrim.c\
	 ft_strsplit.c\
	 ft_itoa.c\
	 ft_putchar_fd.c\
	 ft_putstr_fd.c\
	 ft_putendl_fd.c\
	 ft_putnbr_fd.c\
	 ft_intlong.c\
	 ft_nombre.c\
	 ft_lstnew.c\
	 ft_lstadd.c\
	 ft_lstdel.c\
	 ft_lstdelone.c\
	 ft_lstiter.c\
	 ft_lstmap.c

NAME = libft.a
CC = gcc
INC = -I includes/
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
OBJ = $(SRC:.c=.o)
RM = rm -rf
RANLIB = ranlib

all: $(NAME)

$(NAME): $(OBJ)
	@echo "                            \033[31m[LIBFT]\033[0m : \033[34mCreating Library\033[0m";
	@echo "                            \033[31m[LIBFT]\033[0m : \033[34mIndexing Library\033[0m";
	@$(AR) $(NAME) $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)

depart:
	@echo "                                                                         ";
	@echo "                             _       _________ ______   _______ _________";
	@echo "                            ( \      \__   __/(  ___ \ (  ____ \\__   __/";
	@echo "                            | (         ) (   | (   ) )| (    \/   ) (   ";
	@echo "                            | |         | |   | (__/ / | (__       | |   ";
	@echo "                            | |         | |   |  __ (  |  __)      | |   ";
	@echo "                            | |         | |   | (  \ \ | (         | |   ";
	@echo "                            | (____/\___) (___| )___) )| )         | |   ";
	@echo "                            (_______/\_______/|/ \___/ |/          )_(   ";
	
%.o: %.c
	@echo "                            \033[31m[LIBFT]\033[0m : \033[34mCompiling $<\033[0m";
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "                            \033[31m[LIBFT]\033[0m : \033[34mCleaning object files...\033[0m";
	@$(RM) $(OBJ)

fclean: clean
	@echo "                            \033[31m[LIBFT]\033[0m : \033[34mCleaning Library...\033[0m";
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
