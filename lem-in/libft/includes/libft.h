#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# define BUFF_SIZE 100

/*
**	Types.
*/

# define TRUE	1
# define FALSE	0

/*
**	Singly linked list.
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	Double linked list.
*/

typedef	int 		t_val;

typedef struct		s_node
{
	t_val			value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dlst
{
	size_t			size;
	t_node			*head;
	t_node			*tail;
}					t_dlst;

/*
**	Output.
*/

int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
int				ft_putnstr(char *str, int max);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_putchar_index(char c, size_t *p, int fd);
int				ft_putstr_index(char *str, size_t *p, int fd);
/*
**	Input.
*/

int				get_next_line(const int fd, char **line);

/*
**	Memory.
*/

void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memcpy(void *dst, const void *src, size_t num);
void			ft_bzero(void *s, int n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t num);
void			*ft_memchr(const void *ptr, int value, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_realloc(void *ptr, size_t size);

/*
**	String.
*/

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int character);
char			*ft_strrchr(const char *str, int character);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *big, const char *little, size_t len);
size_t			ft_strcspn(const char *s, const char *reject);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strpbrk(const char *s1, const char *s2);
char			*ft_strtok(char *str, const char sep);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isgraph(int c);
int				ft_iscntrl(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_ispunct(int c);
int				ft_isxdigit(int c);
int				ft_iswspace(int c);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base);

/*
**	Non libc.
*/

void			*ft_memalloc(size_t size);
void			*ft_safe_malloc(size_t size);
void			ft_memdel(void **ap);

void			ft_strclr(char *s);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);

/*
**	List functions.
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lst_del(t_list **lst);
void			ft_lstadd_last(t_list **alst, t_list *n);
t_list			*ft_lst_del_one(t_list *curr, void *value, size_t size);
t_list			*ft_lstnewchar(void const *content, size_t content_size);
void			ft_lstrev(t_list **list);

/*
**	Double linked list functions.
*/

t_dlst			*ft_dlstnew(void);
void			ft_dlstdel(t_dlst **dlst);
_Bool			ft_dlst_push_front(t_dlst *dlst, t_val value);
_Bool			ft_dlst_push_back(t_dlst *dlst, t_val value);
_Bool			ft_dlst_pop_front(t_dlst *dlst, t_val *value);
_Bool			ft_dlst_pop_back(t_dlst *dlst, t_val *value);
_Bool			ft_dlst_peek_front(t_dlst *dlst, t_val *value);
_Bool			ft_dlst_peek_back(t_dlst *dlst, t_val *value);
void			ft_dlst_print(t_dlst *list, void (*f)(t_val value));
t_node*			ft_dlst_get_nth_elem(t_dlst *dlst, size_t index);
_Bool			ft_dlst_del_nth_elem(t_dlst *dlst, size_t index, t_val *value);
_Bool			ft_dlst_add_nth_elem(t_dlst *dlst, size_t index, t_val value);

/*
**	Math.
*/

double			ft_pow(double num, int e);
int				ft_abs(int val);
size_t			ft_nbrlen(int nbr, int base);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

#endif
