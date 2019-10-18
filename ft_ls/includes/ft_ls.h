#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/printf.h"


typedef struct 			s_ldir
{
	size_t 				id;
	char				*fullpath;
	char				*path;
	struct s_ldir		*next;
	struct s_ldir		*prev;
}						t_ldir;

void listdir(const char *name, int indent, t_ldir **lst);

t_ldir		*ft_ldirnew(size_t id, char *path, char *fullpath);
void		ft_ldiradd(t_ldir **alst, t_ldir *new);
t_ldir		*_ft_getdir(t_ldir **alst);
t_ldir		*ft_lastdir(t_ldir *list);

#endif
