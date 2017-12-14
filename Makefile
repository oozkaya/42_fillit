# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 07:29:36 by oozkaya           #+#    #+#              #
#    Updated: 2017/12/05 15:01:24 by oozkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = includes
INC_LIB = ./
INCS = -I $(LIB_PATH)/$(INC_LIB) -I $(INC_DIR)

SRC_DIR = src
SRC = main.c\
	  reader.c\
	  split_tetris.c\
	  checker_init.c\
	  map_creator.c\
	  get_tm_coord.c\
	  map_filler.c\
	  free_allocated_mem.c

OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

C_NO = "\033[00m"
C_DONE = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
DONE = $(C_DONE)DONE$(C_NO)

all: $(NAME)

$(NAME): obj $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_LINK) -o $@
	@echo "Compiling -> " $(NAME) $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<
	@echo "Linking -> " $< $(DONE)

clean:
	@rm -f $(OBJS)
	@rm -Rf $(OBJ_DIR)
	@echo "Cleaning all the Fillit objects -> " $(SUCCESS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) clean_only_lib
	@echo "Deleting -> " $(NAME) $(SUCCESS)

re: fclean all
