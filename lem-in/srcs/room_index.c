#include "lem_in.h"

int	room_index(t_map *m, char *room_name, int start)
{
	int index;

	index = -1;
	while (m->names[++index] && index < m->count_rooms)
	{
		if (ft_strcmp(m->names[index], room_name) == 0)
			return (index);
	}
	return (index);
}
