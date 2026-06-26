# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llarrive <llarrive@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 14:50:39 by llarrive          #+#    #+#              #
#    Updated: 2026/06/01 14:50:39 by llarrive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


########## ARGUMENTS ##########

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

########## VARIABLES ##########

SRC 	= src/main.c \
		  src/execution/execution.c \
		  src/cleanup/cleanup.c \
		  src/builtins/exit.c \
		  src/builtins/pwd.c \
		  src/parsing/parsing.c \
		  src/system/terminal.c

OBJ = $(SRC:.c=.o)

########## RULES ##########

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(LIBS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean :
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY: clean fclean re all
