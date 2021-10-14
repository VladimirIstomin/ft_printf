SRCS		= 

SRCS_B		= 

OBJ_DIR		= obj/

OBJS		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

OBJS_D		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

OBJS_B		= $(addprefix ${OBJ_DIR}, ${SRCS_B:.c=.o})

OBJS_B_D	= $(addprefix ${OBJ_DIR}, ${SRCS_B:.c=.d})

NAME		= libftprintf.a

HEADER		= libftprintf.h

BONUS		= bonus

CC			= gcc

FLAGS		= -Wall -Werror -Wextra -O2 -MMD

${OBJ_DIR}%.o : %.c
			${CC} ${FLAGS} -c $< -o $@

all:		${OBJ_DIR} ${NAME}

${OBJ_DIR}:
			mkdir -p ${OBJ_DIR}

${NAME}:	${OBJS} ${HEADER}
			ar rcs ${NAME} $?

${BONUS}:
			make OBJS='${OBJS} ${OBJS_B}' all

clean:
			rm -rf ${OBJ_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include	${OBJS_D} ${OBJS_B_D}
