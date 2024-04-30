# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npatron <npatron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:08:16 by npatron           #+#    #+#              #
#    Updated: 2024/02/26 13:39:22 by npatron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRC = main.c \
	  utils.c \
	  utils_2.c \
	  parsing.c \
	  init.c \
	  routine.c \
	  elon_musk.c \
	  utils_3.c \
	  

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g 
.c.o:
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
