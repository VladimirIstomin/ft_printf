SRCS		= format_utils.c ft_printf.c length_utils.c\
			write_formatted.c write_utils.c

OBJ_DIR		= obj/

OBJS		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

OBJS_D		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME		= libftprintf.a

HEADER		= ft_printf.h

BONUS		= bonus

CC			= gcc

FLAGS		= -Wall -Werror -Wextra -O2 -MMD

${OBJ_DIR}%.o : %.c
			${CC} ${FLAGS} -c $< -o $@

all:		${OBJ_DIR} ${NAME}

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}

${NAME}:	${OBJS} ${HEADER}
			${MAKE} -C ./libft
			cp libft/libft.a ${NAME}
			ar -rcs ${NAME} ${OBJS}

bonus:		all

clean:
			rm -rf ${OBJ_DIR}
			${MAKE} clean -C ./libft

fclean:		clean
			rm -f ${NAME}
			${MAKE} fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus

-include	${OBJS_D} ${OBJS_B_D}
