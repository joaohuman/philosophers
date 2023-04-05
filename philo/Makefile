# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 23:49:45 by jvictor-          #+#    #+#              #
#    Updated: 2023/04/05 02:08:14 by jvictor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -pthread -Wall -Werror -Wextra
RM = rm -f

SRC = main.c utils_libft.c check_and_init.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $@

$(OBJ): $(SRC)
		$(CC) $(FLAGS) -c $^

clean: 
		$(RM) $(OBJ) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re