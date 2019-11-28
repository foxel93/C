#include "lem_in.h"
#include <stdio.h>
static void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static void	print_result(t_map *m, int n)
{
	int ants;

	if (n == (m->p_ind + m->ants + 1))
		return ;
	ants = m->ants + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= m->p_ind)
			print_ant(ants, m->names[m->path[n - ants]]);
	}
	ft_putchar('\n');
	print_result(m, ++n);
}

void		result(t_map *m)
{
	int i;

	i = -1;
	ft_putendl(m->ants_str);
	ft_putendl(m->rooms_list);
	ft_putendl(m->links_list);
	ft_putchar('\n');
	while (++i <= m->p_ind)
	{
		ft_putchar('[');
		ft_putnbr(m->path[i]);
		ft_putchar(']');
		if (i != m->p_ind)
			ft_putchar('-');
	}
	ft_putstr("\n\n");
	print_result(m, 2);
}
