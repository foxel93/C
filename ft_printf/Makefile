# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:33:53 by ialleen           #+#    #+#              #
#    Updated: 2019/10/11 17:29:17 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	libftprintf.a
FILES:= align_double	align_int		align_uint\
        double          double_helper	flags\
		int				len_int			parse\
		pointer			printf			putnbr\
		size_t			specificators	string\
		uint			utilities\

# ----- Libft ------
LFTDIR:=./libft
# ==================

# ------------------
COMPILER:=gcc
LINKER:=ar rc
SRCPATH:=srcs/
HDRPATH:=includes/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)
CFLAGS:=-Wall -Werror -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(LINKER) $(NAME) $(OBJ) $(LFTDIR)/$(CCHPATH)*.o $(LFTDIR)/$(CCHPATH)/*.o
	@ranlib $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean
	@echo $(GREEN)Objects DELETED $(EOC)

fclean: clean
	@rm -f $(NAME)
	@rm -f test_me
	@rm -rf test_me.dSYM/
	@rm -rf a.out.dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean
	@echo $(GREEN)$(NAME) DELETED $(EOC)

re: fclean
	@$(MAKE) all

test: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) -g -w $(CFLAGS) main.c $(SRC) $(LFLAGS) -o test_me

debug: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) -g $(IFLAGS) main.c $(SRC) $(LFLAGS)

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@echo $(END)
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test norme
