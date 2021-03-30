# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 11:05:35 by lrosendo          #+#    #+#              #
#    Updated: 2021/03/27 12:20:25 by lrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
SRC 	= ft_print_hex.c ft_printf_flags.c ft_printf_utilit.c ft_printf.c \
		ft_putchar.c ft_putstr.c ft_set_flag.c ft_unsigned_itoa.c
OBJ		= ${SRC:.c=.o}
NAME2	= libft/ft_atoi.o libft/ft_calloc.o libft/ft_isdigit.o libft/ft_itoa.o \
		libft/ft_memmove.o libft/ft_strchr.o libft/ft_strdup.o libft/ft_strlen.o \
		libft/ft_bzero.o libft/ft_memcpy.o libft/ft_memset.o
END		= ${OBJ} ${NAME2}
FLAGS 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(NAME2)
	ar -rs $(NAME) $(END)

$(NAME2):
	cd libft && make && cd ..

%.o : %.c
	gcc ${FLAGS} -c -o $@ $<

clean_liba : 
	cd libft && make fclean && cd ..

clean : clean_liba
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
