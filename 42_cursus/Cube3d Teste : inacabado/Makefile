# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 20:05:34 by lrosendo          #+#    #+#              #
#    Updated: 2021/05/08 21:22:34 by lrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SOURCES = test.c func_cub.c colision.c rays.c project_walls.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra #-Werror

LINKS = -I Libft -L Libft \
    -I minilibx/ -L minilibx/\
    -l mlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(SOURCES) -o $(NAME) $(LINKS)
