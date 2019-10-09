NAME = fillit

SRC =   validator.c \
        solver.c \
        main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCLIB= libft

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -c $? -o $@
	@echo "gcc $<"

$(NAME): $(OBJ)
	@$(MAKE) -C $(SRCLIB)
	@$(CC) $(OBJ) libft/libft.a -o $(NAME)
	@echo "fillit compiled"

clean:
	@$(MAKE) clean -C $(SRCLIB)
	@/bin/rm -f $(OBJ)
	@echo "fillit objects deleted"

fclean: clean
	@$(MAKE) fclean -C $(SRCLIB)
	@/bin/rm -f $(NAME)
	@echo "fillit deleted"

re: fclean all