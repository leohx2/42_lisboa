# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 08:44:18 by lrosendo          #+#    #+#              #
#    Updated: 2021/08/13 14:12:06 by lrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC	= push_swap
NAME1	= push_swap.a
LIB		= libft/libft.a
INCLUDE = libft/libft.h
SRC		= push_swap.c ft_putchar.c ft_putstr.c check_error.c \
		util.c util2.c util3.c check_order.c sort_sizes.c a_size.c \
		b_size.c print_result1.c print_result2.c print_result3.c
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror

all: $(EXEC)

debug: $(NAME1) $(LIB)
	@gcc -g $(SRC) $(LIB) -o debug_esse
	@echo "Ready to DEBUG!"

$(EXEC): $(NAME1) $(LIB)
	@gcc $(FLAGS) $(NAME1) $(LIB) -o $(EXEC)
	@echo "Ready to use!"

no_flags: $(NAME1) $(LIB) #Just to try without the fucking flags while I'm finishing it
	@gcc $(NAME1) $(LIB) -o $(EXEC)
	@echo "Ready to use!"

$(NAME1): $(OBJ)
	@ar -rs $(NAME1) $(OBJ)
	@echo "Creating push_swap.a"

%.o : %.c
	@gcc -c -o $@ $< 
#@gcc ${FLAGS} -c -o $@ $< <<<<< VOLTA A COLOCAR ESTE <<<<<<<

$(LIB):
	@cd Libft && make && cd ..

clean:
	@rm -f $(OBJ) && cd Libft && make clean && cd ..
	@echo "Cleaning push_swap"

fclean:
	@rm -f $(NAME1) $(OBJ) && cd Libft && make fclean && cd ..
	@rm -f $(EXEC) @rm -f debug_esse
	@echo "Cleaning push_swap"

re: fclean all