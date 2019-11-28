#include "lem_in.h"

void	ft_exit(t_map *m, int error)
{
	int i;

	free(m->links_list);
	free(m->ants_str);
	free(m->rooms_list);
	if (m->init_2)
	{
		free(m->path);
		free_split(m->names, m, SUCCESS);
		i = -1;
		while (++i < m->count_rooms)
			free(m->tab[i]);
		free(m->tab);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	free_split(char **array, t_map *m, int error)
{
	int i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	if (error == ERROR)
		ft_exit(m, ERROR);
	array = NULL;
}