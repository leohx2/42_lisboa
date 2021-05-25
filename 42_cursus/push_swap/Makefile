# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 08:44:18 by lrosendo          #+#    #+#              #
#    Updated: 2021/05/25 10:32:37 by lrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC	= push_swap
NAME1	= push_swap.a
LIB		= Libft/libft.a
INCLUDE = Libft/libft.h
SRC		= push_swap.c ft_putchar.c ft_putstr.c check_error.c \
		order_a.c order_b.c check_order.c
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror

all: $(EXEC)

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
	@rm -f $(EXEC)
	@echo "Cleaning push_swap"

re: fclean all