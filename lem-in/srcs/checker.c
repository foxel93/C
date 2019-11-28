#include "lem_in.h"



static void checker_commands(t_map *m)
{
	if (m->line[0] == '#' && m->line[1] == '#')
	{
		if (ft_strequ(m->line, "##start"))
			m->start_end[0] == -1 ? m->start_end[0] = 1 : ft_exit(m, ERROR);
		else if (ft_strequ(m->line, "##end"))
			m->start_end[1] == -1 ? m->start_end[1] = 1 : ft_exit(m, ERROR);
	}
	free(m->line);
	m->line = NULL;
}

static void	checker_ants(t_map *m)
{
	m->started = 1;
	((m->ants = ft_atoi(m->line)) <= 0) ? ft_exit(m, ERROR) : 0;
	(ft_strlen(m->line) != ft_nbrlen(m->ants, 10)) ? ft_exit(m, ERROR) : 0;
	free(m->line);
	m->line = NULL;
}

static void	rooms(t_map *m)
{
	char **r;

	m->started = 2;
	m->count_rooms == -1 ? m->count_rooms = 1 : m->count_rooms++;
	(!(m->rooms_list = ft_strjoin_free_ln(m->rooms_list, m->line))) ? ft_exit(m, ERROR) : 0;
	(!(r = ft_strsplit(m->line, ' '))) ? ft_exit(m, ERROR) : 0;
	(r[0][0] == 'L' || r[3] != NULL) ? free_split(r, m, ERROR) : 0;
	(ft_strlen(r[0]) != ft_nbrlen(ft_atoi(r[0]), 10)) ? free_split(r, m, ERROR) : 0;
	(ft_strlen(r[1]) != ft_nbrlen(ft_atoi(r[1]), 10)) ? free_split(r, m, ERROR) : 0;
	free_split(r, m, SUCCESS);
	m->start_end[0] == 1 && m->start_end[1] == 1 ? ft_exit(m, ERROR) : 0;
	if (m->start_end[0] == 1)
	{
		m->start_end[0] = 0;
		m->pos_start_end[0] = m->count_rooms - 1;
	}
	else if (m->start_end[1] == 1)
	{
		m->start_end[1] = 0;
		m->pos_start_end[1] = m->count_rooms - 1;
	}
	free(m->line);
	m->line = NULL;
}

static void	links(t_map *m)
{
	char *pos;

	(m->started == 2) ? m->started = 3 : 0;
	(m->started != 3) ? ft_exit(m, ERROR) : 0;
	(!(m->links_list = ft_strjoin_free_ln(m->links_list, m->line))) ? ft_exit(m, ERROR) : 0;
	pos = ft_strchr(m->line, '-') + 1;
	if (ft_strlen(m->line) != ft_nbrlen(ft_atoi(m->line), 10) + ft_nbrlen(ft_atoi(pos), 10) + 1)
		ft_exit(m, ERROR);
	free(m->line);
	m->line = NULL;
}

void		checker(t_map *m)
{
	char *tmp;

	while (get_next_line(STDIN_FILENO, &m->line) > 0)
	{
		if (m->line[0] == '\0')
			break;
		(!(tmp = ft_strtrim(m->line))) ? ft_exit(m, ERROR) : 0;
		m->line = tmp;
		if (m->line[0] == '#')
			checker_commands(m);
		else if (m->ants == -1)
			checker_ants(m);
		else if (ft_strchr(m->line, '-'))
			links(m);
		else if ((m->started == 1 || m->started == 2) && m->line[0] != '\0')
			rooms(m);
		else
			ft_exit(m, ERROR);
	}
	if (m->ants == -1 || !m->links_list[0])
		ft_exit(m, ERROR);
	if (m->start_end[0] !=0 || m->start_end[1] != 0)
		ft_exit(m, ERROR);
}