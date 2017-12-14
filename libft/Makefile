#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 08:30:25 by oozkaya           #+#    #+#              #
#    Updated: 2017/12/14 09:18:11 by oozkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = ./

SRC =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_abs.c \
		ft_strlwr.c ft_strupr.c ft_islower.c ft_isupper.c ft_capitalize.c \
		ft_strnjoin.c ft_strjoinfree.c ft_strnjoinfree.c ft_strndup.c \
		ft_int_sqrt.c ft_sqrt.c

OBJ = $(SRC:.c=.o)

C_NO = "\033[00m"
C_DONE = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
DONE = $(C_DONE)DONE$(C_NO)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing -> " $(NAME) $(SUCCESS)

%.o: %.c $(INC_DIR)/*.h
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_DIR)
	@echo "Linking -> " $< $(DONE)

clean:
	@/bin/rm -f $(OBJ)
	@echo "Cleaning all the Libft objects -> " $(SUCCESS)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Deleting -> " $(NAME) $(SUCCESS)

clean_only_lib:
	@/bin/rm -f $(NAME)
	@echo "Deleting -> " $(NAME) $(SUCCESS)

re: fclean all
