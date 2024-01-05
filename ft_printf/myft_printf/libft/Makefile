# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:03:38 by leng-chu          #+#    #+#              #
#    Updated: 2024/01/04 13:05:41 by leng-chu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC = \
	  ft_isdigit.c ft_itoa.c ft_strlen.c ft_substr.c ft_toupper.c \
	  ft_itoa_hex.c ft_uitoa.c ft_ulitoa_hex.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
