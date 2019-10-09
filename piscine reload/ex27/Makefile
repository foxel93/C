# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 15:04:46 by ialleen           #+#    #+#              #
#    Updated: 2019/09/02 15:56:36 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_display_file

SOURCES =	srcs/main.c

INCLUDES = 	includes/*.h

OBJECTS	 = 	main.c

all: $(NAME)

$(NAME): 	
			@gcc -Wall -Wextra -Werror -o $(NAME) $(SOURCES)
clean:
			@/bin/rm -f $(OBJECTS)
fclean: clean
			@/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
