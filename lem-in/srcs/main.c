#include "lem_in.h"

static t_map	*map_init_2(t_map *m)
{
	int i;
	int j;

	i = -1;
	m->init_2 = 1;
	m->path = (int*)ft_memalloc(sizeof(int) * 1000);
	m->tab = (int**)ft_memalloc(sizeof(int*) * m->count_rooms);
	m->names = (char**)ft_memalloc(sizeof(char*) * (m->count_rooms + 1));
	while (++i < m->count_rooms)
	{
		m->path[i] = -1;
		m->names[i] = NULL;
		m->tab[i] = (int*)ft_memalloc(sizeof(int) * m->count_rooms);
		j = -1;
		while (m->tab[i][++j])
			m->tab[i][j] = 0;
	}
	m->names[i] = NULL;
	m->path[0] = 0;
	return (m);
}

static t_map	*map_init(void)
{
	t_map *m;

	(!(m = (t_map*)malloc(sizeof(t_map)))) ? ft_exit(m, ERROR) : 0;
	(!(m->links_list = ft_strnew(1))) ? ft_exit(m, ERROR) : 0;
	(!(m->ants_str = ft_strnew(1))) ? ft_exit(m, ERROR) : 0;
	(!(m->rooms_list = ft_strnew(1))) ? ft_exit(m, ERROR) : 0;
	m->count_rooms = -1;
	m->ants = -1;
	m->started = -1;
	m->curr_room = 0;
	m->p_ind = 0;
	m->init_2 = -1;
	m->start_end[0] = -1;
	m->start_end[1] = -1;
	m->pos_start_end[0] = -1;
	m->pos_start_end[1] = -1;
	m->names = NULL;
	m->tab = NULL;
	m->path = NULL;
	return (m);
}

int				main(void)
{
	t_map *m;

	m = map_init();
	checker(m);
	m = map_init_2(m);
	add_rooms(m);
	create_tab(m);
	print_matrix(m);
	if (solution(m, 0))
		result(m);
	else
		ft_exit(m, ERROR);
	ft_exit(m, SUCCESS);
}
