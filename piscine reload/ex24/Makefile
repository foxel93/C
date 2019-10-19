# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 15:04:46 by ialleen           #+#    #+#              #
#    Updated: 2019/09/02 15:29:05 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SOURCES =	srcs/ft_putchar.c \
			srcs/ft_putstr.c \
	  		srcs/ft_strcmp.c \
	  		srcs/ft_strlen.c \
	  		srcs/ft_swap.c

INCLUDES = 	includes/*.h

OBJECTS	 = 	ft_putchar.o \
			ft_putstr.o \
			ft_strcmp.o \
			ft_strlen.o \
			ft_swap.o

all: $(NAME)

$(NAME): 	
			@gcc -Wall -Wextra -Werror -c $(SOURCES)
			@ar rc $(NAME) $(OBJECTS)
clean:
			@/bin/rm -f $(OBJECTS)
fclean: clean
			@/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
