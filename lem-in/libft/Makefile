CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

NAME = libft.a

DEPS =	$(IDIR)/libft.h \
		$(IDIR)/ft_printf.h \
		$(IDIR)/ft_printf_types.h

SDIR = srcs
IDIR = includes
ODIR = obj

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(SRC))
SRC =	$(_SRC) \
		$(addprefix printf/,$(_SRC_FTFPRINTF))
		$(addprefix $(_CTYPE_DIR)/,$(_SRC_FTFPRINTF))

_CTYPE_DIR = ./ctype







_CTYPE = ft_isalnum.c \
         ft_isalpha.c \
         ft_isascii.c \
         ft_isblank.c \
         ft_iscntrl.c \
         ft_isdigit.c \
         ft_isgraph.c \
         ft_islower.c \
         ft_isprint.c \
         ft_ispunct.c \
         ft_isspace.c \
         ft_iswspace.c \
         ft_isupper.c \
         ft_isxdigit.c \
         ft_tolower.c \
         ft_toupper.c \

_SRC =
		./list/ft_lstadd.c \
		./list/ft_lstdel.c \
		./list/ft_lstdelone.c \
		./list/ft_lstiter.c \
		./list/ft_lstmap.c \
		./list/ft_lstnew.c \
		./list/ft_lstnewchar.c \
		./list/ft_lst_del_one.c \
		./list/ft_lstadd_last.c \
		./list/ft_lst_del.c \
		./list/ft_lstrev.c \
		./dlist/ft_dlstadd.c \
		./dlist/ft_dlstdel.c \
		./dlist/ft_dlstdelone.c \
		./dlist/ft_dlstiter.c \
		./dlist/ft_dlstmap.c \
		./dlist/ft_dlstnew.c \
		./dlist/ft_dlstfirst.c \
		./memory/ft_bzero.c \
		./memory/ft_safe_malloc.c \
		./memory/ft_memalloc.c \
		./memory/ft_memccpy.c \
		./memory/ft_memchr.c \
		./memory/ft_memcmp.c \
		./memory/ft_memcpy.c \
		./memory/ft_memdel.c \
		./memory/ft_memmove.c \
		./memory/ft_memset.c \
		./memory/ft_realloc.c \
		./output/ft_putchar.c \
		./output/ft_putchar_fd.c \
		./output/ft_putendl.c \
		./output/ft_putendl_fd.c \
		./output/ft_putnbr.c \
		./output/ft_putnbr_fd.c \
		./output/ft_putstr.c \
		./output/ft_putstr_fd.c \
		./output/ft_putnstr.c \
		./string/ft_itoa.c \
		./string/ft_itoa_base.c \
		./string/ft_strcat.c \
		./string/ft_strchr.c \
		./string/ft_strclr.c \
		./string/ft_strcmp.c \
		./string/ft_strcpy.c \
		./string/ft_strcspn.c \
		./string/ft_strdel.c \
		./string/ft_strdup.c \
		./string/ft_strndup.c \
		./string/ft_strequ.c \
		./string/ft_striter.c \
		./string/ft_striteri.c \
		./string/ft_strjoin_free.c \
		./string/ft_strjoin.c \
		./string/ft_strlcat.c \
		./string/ft_strlen.c \
		./string/ft_strmap.c \
		./string/ft_strmapi.c \
		./string/ft_strncat.c \
		./string/ft_strncmp.c \
		./string/ft_strncpy.c \
		./string/ft_strnequ.c \
		./string/ft_strnew.c \
		./string/ft_strnstr.c \
		./string/ft_strpbrk.c \
		./string/ft_strrchr.c \
		./string/ft_strsplit.c \
		./string/ft_strspn.c \
		./string/ft_strstr.c \
		./string/ft_strsub.c \
		./string/ft_strtok.c \
		./string/ft_strtrim.c \
		./input/get_next_line.c \
		./math/ft_max.c \
		./math/ft_min.c \
		./math/ft_pow.c \
		./math/ft_abs.c \
		./math/ft_nbrlen.c

_SRC_FTFPRINTF = \
        align_double.c \
        align_int.c \
        align_uint.c \
        double.c \
        double_helper.c	\
        flags.c\
        int.c \
        len_int.c \
        parse.c \
        pointer.c \
        printf.c \
        putnbr.c \
        size_t.c \
        specificators.c \
        string.c \
        uint.c \
        utilities.c \

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
