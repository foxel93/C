#include "push_swap.h"

static size_t	check_rrr(t_info *info)
{
	size_t i;
	t_val	curr;
	t_val	next;
	i = -1;
	while (++i < info->cmds->size - 1)
	{
		curr = get_nth_elem(info->cmds, i)->value;
		next = get_nth_elem(info->cmds,  i + 1)->value;
		if ((curr == PA && next == PB) || (curr == PB && next == PA) ||
			(curr == RA && next == RRA) || (curr == RB && next == RRB) ||
			(curr == RRA && next == RA) || (curr == RRB && next == RB))
		{
			delete_nth_elem(info->cmds, i + 1, NULL);
			delete_nth_elem(info->cmds, i, NULL);
		}
		else if ((curr == RA && next == RB) || (curr == RRA && next == RRB))
		{
			delete_nth_elem(info->cmds, i + 1, NULL);
			change_nth_elem(info->cmds, i, curr + next);
		}
	}
	return (info->cmds->size);
}

void	optimizer(t_info *info)
{
	size_t size;
	size_t new_size;

	while (1)
	{
		size = info->cmds->size;
		if (size < 1)
			break;
		new_size = check_rrr(info);
		if (size == new_size)
			break ;
	}
}