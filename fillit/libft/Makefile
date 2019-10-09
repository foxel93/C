# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 10:26:24 by ialleen           #+#    #+#              #
#    Updated: 2019/09/13 17:10:58 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c\
			ft_isascii.c	ft_lstdel.c		ft_isdigit.c	ft_isprint.c	ft_itoa.c\
			ft_lstadd.c		ft_lstdelone.c	ft_lstiter.c	ft_lstmap.c		ft_lstnew.c\
			ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
			ft_memdel.c		ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c\
			ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c\
			ft_putstr_fd.c	ft_realloc.c	ft_strcat.c		ft_strchr.c		ft_strclr.c\
			ft_strcmp.c		ft_strcpy.c		ft_strcspn.c	ft_strdel.c		ft_strdup.c\
			ft_strequ.c		ft_striter.c	ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
			ft_strlen.c		ft_strmap.c		ft_strmapi.c	ft_strncat.c	ft_strncmp.c\
			ft_strncpy.c	ft_strnequ.c	ft_strnew.c		ft_strnstr.c	ft_strrchr.c\
			ft_strsplit.c	ft_strspn.c		ft_strstr.c		ft_strsub.c		ft_strtok.c\
			ft_strtrim.c	ft_tolower.c	ft_toupper.c	ft_strlcmp.c	ft_strlcpy.c\
			ft_strpbrk.c	ft_isblank.c	ft_iscntrl.c	ft_isgraph.c	ft_islower.c\
			ft_ispunct.c	ft_isspace.c	ft_isupper.c	ft_isxdigit.c	ft_strndup.c\
			get_next_line.c

DEPS = libft.h
MDEPS = $(DEPS:.h=.h)

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.h: %.h

%.o: %.c
	@$(CC) -c $? -o $@

$(NAME): $(OBJ) $(MDEPS)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "libft compiled"

clean:
	@/bin/rm -f $(OBJ)
	@echo "libft objects deleted"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "libft.a deleted"

re: fclean all

.PHONY = all clean fclean re
