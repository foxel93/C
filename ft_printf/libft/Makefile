# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 10:26:24 by ialleen           #+#    #+#              #
#    Updated: 2019/10/11 17:26:24 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libft.a

FILES:= 	ft_atoi			ft_bzero		ft_calloc	ft_isalnum		ft_isalpha\
			ft_isascii		ft_lstdel		ft_isdigit	ft_isprint		ft_itoa\
			ft_lstadd		ft_lstdelone	ft_lstiter	ft_lstmap		ft_lstnew\
			ft_memalloc		ft_memccpy		ft_memchr	ft_memcmp		ft_memcpy\
			ft_memdel		ft_memmove		ft_memset	ft_putchar		ft_putchar_fd\
			ft_putendl		ft_putendl_fd	ft_putnbr	ft_putnbr_fd	ft_putstr\
			ft_putstr_fd	ft_realloc		ft_strcat	ft_strchr		ft_strclr\
			ft_strcmp		ft_strcpy		ft_strcspn	ft_strdel		ft_strdup\
			ft_strequ		ft_striter		ft_striteri	ft_strjoin		ft_strlcat\
			ft_strlen		ft_strmap		ft_strmapi	ft_strncat		ft_strncmp\
			ft_strncpy		ft_strnequ		ft_strnew	ft_strnstr		ft_strrchr\
			ft_strsplit		ft_strspn		ft_strstr	ft_strsub		ft_strtok\
			ft_strtrim		ft_tolower		ft_toupper	ft_strlcmp		ft_strlcpy\
			ft_strpbrk		ft_isblank		ft_iscntrl	ft_isgraph		ft_islower\
			ft_ispunct		ft_isspace		ft_isupper	ft_isxdigit		ft_strndup\
			get_next_line	ft_putnstr		ft_count	ft_pow			ft_putchar_index\
			ft_putstr_index

# ==== Standard ====
CC:=gcc
CCHPATH:=obj/
SRCPATH:= ./
HDRPATH:= ./
CFLAGS:=-Wall -Wextra -Werror -I $(HDRPATH)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ==== Src & Obj ===
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo ".\c"
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
