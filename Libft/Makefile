# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 16:41:07 by lrosendo          #+#    #+#              #
#    Updated: 2021/02/16 16:41:07 by lrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*- 

NAME = libft.a
HEADER = libft.h
SRC = ${wildcard ft_*.c}
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	ar -rs ${NAME} ${OBJ}

%.o: %.c 
	gcc ${FLAGS} -c -o $@ $<

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJ}

.PHONY: clean
fclean: clean
	rm -f ${NAME}

re: fclean all
