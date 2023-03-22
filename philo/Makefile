# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 23:49:45 by jvictor-          #+#    #+#              #
#    Updated: 2023/03/23 00:03:59 by jvictor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc 
FLAGS = -pthread -Wall -Werror -Wextra
RM = rm -f

SRC = main.c

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