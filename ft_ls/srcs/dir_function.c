#include "../includes/ft_ls.h"

t_ldir	*ft_lastdir(t_ldir *list)
{
	if (list == NULL)
		return (NULL);
	while (list && list->next)
		list = list->next;
	return (list);
}

t_ldir	*_ft_getdir(t_ldir **alst)
{
	t_ldir *tmp;

	tmp = NULL;
	if (alst && *alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
	}
	return (tmp);
}

void	ft_ldiradd(t_ldir **alst, t_ldir *new)
{
	if (alst && new)
	{
		new->next = *alst;
		(*alst)->prev = new;
		*alst = new;
	}
}

t_ldir		*ft_ldirnew(size_t id, char *path, char *fullpath)
{
	t_ldir	*ldir;
	if (!(ldir = (t_ldir *)malloc(sizeof(t_ldir))))
	{
		free(fullpath);
		return (NULL);
	}
	ldir->path = path;
	ldir->fullpath = fullpath;
	ldir->id = id;
	ldir->next = NULL;
	ldir->prev = NULL;
	return (ldir);
}
