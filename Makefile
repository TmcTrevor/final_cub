SRCS_CUB3D = $(wildcard src/*.c)

SRCS_LIBFT = $(wildcard libft/*.c)
SRCS_GNL = GNL/get_next_line.c 
SRCS_PARSE = ${wildcard src/parse/*.c}
SRCS = ${SRCS_CUB3D} ${SRCS_GNL} ${SRCS_LIBFT} ${SRCS_PARSE}

INCL = -I includes/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : ${OBJS}
		gcc   -I /usr/local/include -o $(NAME) ${OBJS} -L /usr/local/lib -lmlx -framework Opengl -framework AppKit libftprintf.a
	
.c.o : ${SRCS}
		gcc  -c ${INCL} $< -o ${<:.c=.o}
clean :
		rm -f ${OBJS}
fclean : clean
		rm -f $(NAME)
re : fclean
		make all
.PHONY: all clean fclean re