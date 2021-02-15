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

clean:
	rm -f ${OBJ}

.PHONY: clean
fclean: clean
	rm -f ${NAME}

re: fclean all
