#include "push_swap.h"

static void	print_cmd(size_t num)
{
	num == SA ? ft_putstr("sa\n") : 0;
	num == SB ? ft_putstr("sb\n") : 0;
	num == SS ? ft_putstr("ss\n") : 0;
	num == RA ? ft_putstr("ra\n") : 0;
	num == RB ? ft_putstr("rb\n") : 0;
	num == RR ? ft_putstr("rr\n") : 0;
	num == RRA ? ft_putstr("rra\n") : 0;
	num == RRB ? ft_putstr("rrb\n") : 0;
	num == RRR ? ft_putstr("rrr\n") : 0;
	num == PA ? ft_putstr("pa\n") : 0;
	num == PB ? ft_putstr("pb\n") : 0;
}

void	print_cmds(t_info *info)
{
	size_t i;

	i = -1;
	while (++i < info->cmds->size)
		print_cmd(get_nth_elem(info->cmds, i)->value);
}

void	display_stacks(t_info *info)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	size_t i;
	size_t m;

	stack_a = info->a;
	stack_b = info->b;
	m = MAX(stack_a->size, stack_b->size);
	i = -1;
	usleep(120000);
	ft_putstr("\E[H\E[2J");
	ft_printf("%15s   %-15s\n", "Stack A", "Stack B");
	while (++i < m)
	{

		if (i < stack_a->size && i < stack_b->size)
			ft_printf("%15d | %-15d\n", get_val(stack_a, i), get_val(stack_b, i));
		else if (i < stack_a->size && i >= stack_b->size)
			ft_printf("%15d | %-15c\n", get_val(stack_a, i), ' ');
		else if (i >= stack_a->size && i < stack_b->size)
			ft_printf("%15c | %-15d\n", ' ',get_val(stack_b, i));
	}
}