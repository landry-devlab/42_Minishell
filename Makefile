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

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = -lreadline

NAME = minishell

# LIBFT_DIR = libft
# LIBFT_LIB = $(libft)/libft.a


########## VARIABLES ##########

SRC 	= src/main.c \
		  src/prompt/prompt_test_v0.0.c \
		  src/execution/execution.c \
		  src/system/terminal.c \
		  libft/libft_functions_test_0.0.c

OBJ = $(SRC:.c=.o)

########## RULES ##########

all: $(NAME)

# $(NAME): $(OBJ) $(LIFT_LIB)
#	$(CC) $(CFLAGS) $(OBJ)$(LIBFT_LIB) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)


# $(LIBFT_LIB):
# 	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

# clean :
# 	rm -rf $(OBJ)
#	$(MAKE) -C $(LIBFT_DIR) clean

# fclean : clean
# 	rm -rf $(NAME)
# 	$(MAKE) -C $(LIBFT_DIR) fclean

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all



re : fclean all

.PHONY: clean fclean re all
