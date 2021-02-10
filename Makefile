SRCS_CUB3D = $(wildcard src/*.c)

SRCS_GNL = GNL/get_next_line.c 
SRCS_PARSE = ${wildcard src/parse/*.c}
SRCS = ${SRCS_CUB3D} ${SRCS_GNL} ${SRCS_PARSE}

INCL = -I includes/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

all : libft_make mlxmake $(NAME)

$(NAME) : ${OBJS}
	@cp ./minilibx/libmlx.dylib .
	@cp ./libft/libft.a .
	@gcc  -g  ${FLAGS} -I /usr/local/include -o $(NAME) ${OBJS} libft.a -I ./minilibx libmlx.dylib -L /usr/local/lib -lmlx -framework Opengl -framework AppKit -fsanitize=address

libft_make : 
	@ $(MAKE) -C libft

mlxmake :
	@$(MAKE)	-C minilibx

mlxclean:
	$(MAKE)	-C minilibx	clean

clean :	mlxclean
		rm -f libmlx.dylib
		rm -f ${OBJS}
		rm -f libft/libft.a
		rm -f libft.a
fclean : clean
		rm -f $(NAME)

re : fclean
		make all
.PHONY: all clean fclean re