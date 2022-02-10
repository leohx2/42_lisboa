# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosendo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 20:46:46 by lrosendo          #+#    #+#              #
#    Updated: 2022/02/10 21:59:58 by lrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Libft/libft.a
SOURCE	= error.c
SERVER	= server.c
CLIENT	= client.c
OBJ		= ${SOURCE:.c=.o}
COMP	= gcc #/*COLOCAR FLAGs*/
EXEC1	= server
EXEC2	= client

all: ${NAME} ${EXEC1} ${EXEC2}

${NAME}: ${OBJ}
	@cd Libft && make && cd ..

${EXEC1}: ${NAME} ${SERVER}
	${COMP} ${SERVER} ${NAME} ${SOURCE} -o ${EXEC1}

${EXEC2}: ${NAME} ${CLIENT}
	${COMP} ${CLIENT} ${NAME} ${SOURCE} -o ${EXEC2}

clean:
	@cd libft && make clean && cd .. && rm ${OBJ}

fclean: clean
	@rm ${NAME} ${EXEC1} ${EXEC2}

re: fclean all #arrumar re
