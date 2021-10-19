SRCS		= format_utils.c ft_printf.c length_utils.c\
			write_formatted.c write_utils.c

SRCS_B		= format_utils_bonus.c ft_printf_bonus.c length_utils_bonus.c\
			write_formatted_bonus.c write_utils_bonus.c

OBJ_DIR		= obj/

POBJS		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

POBJS_B		= $(addprefix ${OBJ_DIR}, ${SRCS_B:.c=.o})

POBJS_D		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

POBJS_B_D	= $(addprefix ${OBJ_DIR}, ${SRCS_B:.c=.d})

NAME		= libftprintf.a

PHEADER		= ft_printf.h

PHEADER_B	= ft_printf_bonus.h

CC			= gcc

FLAGS		= -Wall -Werror -Wextra -O2 -MMD

${OBJ_DIR}%.o : %.c
			${CC} ${FLAGS} -c $< -o $@

all:		${OBJ_DIR} ${NAME}

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}

${NAME}:	${POBJS} ${PHEADER}
			${MAKE} -C ./libft
			cp libft/libft.a ${NAME}
			ar -rcs ${NAME} ${POBJS}

bonus:		
			@make POBJS='${POBJS_B}' PHEADER='${PHEADER_B}' all

clean:
			rm -rf ${OBJ_DIR}
			${MAKE} clean -C ./libft

fclean:		clean
			rm -f ${NAME}
			${MAKE} fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus

-include	${POBJS_D} ${POBJS_B_D}
