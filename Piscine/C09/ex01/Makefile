# -*- MakeFile -*- 

#target: dependencies
#	action  --> make file sintax, it's NEED to be a TAB insted SPACE before the "action"

NAME = libft.a
INCLUDE = includes
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	ar -rs ${NAME}

%.o: %.c #the % is used as a WildCard, its mean its take the pattern .o (because is %.o) and the pattern .c
	gcc ${FLAGS} -c -o $@ $< -I ${INCLUDE}

all: ${NAME}

clean:
	rm -f srcs/ft_*.o

fclean: clean
	rm -f libft.a

re: fclean libft.a
