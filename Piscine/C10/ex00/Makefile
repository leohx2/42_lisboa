# -*- MakeFile -*-

EXEC = ft_display_file
NAME = libdisplay.a
SRC = files/errors.c files/ft_display_file.c files/main.c
OBJ = ${SRC:.c=.o}
COMP = gcc -Wall -Wextra -Werror
INCLUDE = include
MAIN = files/main.o

${EXEC}: ${NAME}
	${COMP} -o ${EXEC}. ${MAIN} ${NAME}

${NAME}: ${OBJ}
	ar -rs ${NAME}

%.o: %.c
	${COMP} -c -o $@ $<

all: ${EXEC}

clean:
	rm -f files/*.o

fclean: clean
	rm -f ft_display_file libdisplay.a