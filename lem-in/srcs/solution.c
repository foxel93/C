#include "lem_in.h"

static _Bool	is_last_room(t_map *m, int i)
{
	if (m->tab[i][m->count_rooms - 1])
	{
		m->path[++(m->p_ind)] = i;
		m->path[++(m->p_ind)] = m->count_rooms - 1;
		return (TRUE);
	}
	return (FALSE);
}

static void	erase_element(t_map *m, int i, int path)
{
	m->tab[m->curr_room][i] = 0;
	m->tab[i][m->curr_room] = 0;
	if (path)
	{
		m->path[m->p_ind] = -1;
		m->p_ind--;
	}
}

static int	find_door(t_map *m, int r_index, int d_index)
{
	while (d_index < m->count_rooms)
	{
		if (m->tab[r_index][++d_index] == 1)
			return (d_index);
	}
	return (0);
}

static _Bool	is_in_path(t_map *m, int r_index)
{
	int i;

	i = -1;
	while (m->path[++i] != -1)
	{
		if (m->path[i] == r_index)
			return (TRUE);
	}
	return (FALSE);
}

_Bool			solution(t_map *m, int i)
{
	if (m->tab[0][m->count_rooms - 1])
	{
		m->path[++(m->p_ind)] = m->count_rooms - 1;
		return (TRUE);
	}
	while ((i = find_door(m, m->curr_room, i)))
	{
		if (is_last_room(m, i))
			return (TRUE);
		else if (is_in_path(m, i))
			erase_element(m, i, 0);
	}
	if ((m->curr_room = find_door(m, m->curr_room, 0)) == 0)
	{
		if (m->p_ind == 0 || m->curr_room == 0)
			return (FALSE);
		m->curr_room = m->path[m->p_ind - 1];
		erase_element(m, m->path[m->p_ind], 1);
		if (solution(m, 0))
			return (TRUE);
	}
	m->path[++(m->p_ind)] = m->curr_room;
	if (solution(m, 0))
		return (TRUE);
	return (FALSE);
}
