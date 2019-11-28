#include "lem_in.h"
#include <stdio.h>
void		create_tab(t_map *m)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	if (!(links = ft_strsplit(m->links_list, '\n')))
		ft_exit(m, ERROR);
	while (links[++i])
	{
		if (!(l = ft_strsplit(links[i], '-')))
			free_split(links, m, ERROR);
		printf("s: %s %s\n", l[0], l[1]);
		r_1 = room_index(m, l[0], 1);
		r_2 = room_index(m, l[1], 1);
		if (r_1 >= m->count_rooms || r_2 >= m->count_rooms)
		{
			free_split(l, m, SUCCESS);
			free_split(links, m, ERROR);
		}
		(m->tab[r_1][r_2] = 1);
		(m->tab[r_2][r_1] = 1);
		free_split(l, m, SUCCESS);
	}
	free_split(links, m, SUCCESS);
}
