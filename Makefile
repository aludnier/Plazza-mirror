##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## plazza
##


SRC =	main.c		\
		$(addprefix src/,	\
			Cook.cpp		\
			Kitchen.cpp		\
			LineParser.cpp	\
			Reception.cpp	\
		)\

OBJ = ${SRC:.c=.o}

CPPFLAGS += -iquote include/

NAME = plazza

CC = clang++

all: ${NAME}


${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${CPPFLAGS}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re