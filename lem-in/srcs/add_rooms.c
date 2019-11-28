#include "lem_in.h"

static void	is_valid(t_map *m, int i, char **r, char **line)
{
	int r_index;

	r_index = room_index(m, r[0], 0);
	if ((r_index > 0 && i != r_index) || !(m->names[i] = ft_strdup(r[0])))
	{
		free_split(r, m, SUCCESS);
		free_split(line, m, ERROR);
	}
}

static void	check_start_end(t_map *m, char **r, int end, char **line)
{
	if (end)
	{
		if (!(m->names[m->count_rooms - 1] = ft_strdup(r[0])))
		{
			free_split(r, m, SUCCESS);
			free_split(line, m, ERROR);
		}
		return;
	}
	if (!(m->names[0] = ft_strdup(r[0])))
	{
		free_split(r, m, SUCCESS);
		free_split(line, m, ERROR);
	}
}

void		add_rooms(t_map *m)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	if (!(line = ft_strsplit(m->rooms_list, '\n')))
		ft_exit(m, ERROR);
	if (!(m->names = (char **)malloc(sizeof(char *) * m->count_rooms)))
		free_split(line, m, ERROR);
	while (line[++i] && j < m->count_rooms)
	{

		if (!(r = ft_strsplit(line[i], ' ')))
			free_split(line, m, ERROR);
		if (i == m->pos_start_end[0])
			check_start_end(m, r, 0, line);
		else if (i == m->pos_start_end[1])
			check_start_end(m, r, 1, line);
		else
			is_valid(m, j++, r, line);
		free_split(r, m, SUCCESS);
	}
	free_split(line, m, SUCCESS);
	i = -1;
	while (++i < m->count_rooms){
		ft_printf("n:  %s\n", m->names[i]);
	}
}
