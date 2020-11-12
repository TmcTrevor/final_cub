# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokhames <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 18:24:41 by mokhames          #+#    #+#              #
#    Updated: 2019/10/22 18:16:57 by mokhames         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memccpy.c ft_memchr.c\
	  ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
	  ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
	  ft_putstr_fd.c ft_split.c ft_strcapitalize.c ft_strcat.c ft_strchr.c\
	  ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
	  ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c\
	  ft_strrchr.c ft_strstr.c ft_strtrim.c ft_strtrimpalin.c ft_substr.c ft_tolower.c\
	  ft_toupper.c ft_word_count.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c

OBJECT = $(SRC:.c=.o)

OBJECT_BONUS = $(SRC_BONUS:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

bonus :
	@gcc -Wall -Wextra -Werror -c $(SRC_BONUS)
	@ar rc $(NAME) $(OBJECT_BONUS)
	@ranlib $(NAME)

clean :
	@rm -rf $(OBJECT) 
	@rm -rf $(OBJECT_BONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
