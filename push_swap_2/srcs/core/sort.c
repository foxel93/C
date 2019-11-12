#include "push_swap.h"

_Bool	check_sorted(t_stack *stack, int mode)
{
	size_t i;

	i = stack->size;
	while (--i > 0)
	{
		if ((mode == INC && get_val(stack, i - 1) > get_val(stack, i)) ||
			(mode == DEC && get_val(stack, i - 1) < get_val(stack, i)))
			return (FALSE);
		if (i == 1)
			break ;
	}
	return (TRUE);
}

static void	sort_three(t_info *info, size_t i)
{
	size_t max_idx;
	t_stack *stack;

	stack = (i == STACK_A) ? info->a : info->b;
	if (stack->size == 1)
		return ;
	if (stack->size == 2)
	{
		if (get_val(stack, 1) < get_val(stack, 0))
			operation(info, SA + i);
		return ;
	}
	else if (stack->size == 3)
	{
		max_idx = find_min_max_index(stack, F_MAX);
		if (max_idx == 0)
			operation(info, RA + i);
		if (max_idx == 1)
			operation(info, RRA + i);
		if (get_val(stack, 0) > get_val(stack, 1))
			operation(info, SA + i);
	}
}

static void	sort_five(t_info *info)
{
	t_val min;
	size_t pos;
	size_t avg;

	while (info->a->size > 3)
	{
		min = find_min_max_elem(info->a, F_MIN);
		pos = find_min_max_index(info->a, F_MIN);
		avg = get_mlen(info->a->size - 1) - 1;
		while (pos <= avg && get_val(info->a, 0) != min)
			operation(info, RA);
		while (pos > avg && get_val(info->a, 0) != min)
			operation(info, RRA);
		operation(info, PB);
	}
	sort_three(info, STACK_A);
	while (info->b->size != 0)
		operation(info, PA);
}

static void	sort_big(t_info *info)
{
	int				max;
	int				steps;
	int				op;

	while (info->a->size > 0 && operation(info, PB))
		if (info->b->size != 0)
		{
			get_min_steps(info);
			info->total_steps -= info->steps_a + info->steps_b ;
			while (info->steps_a-- > 0)
				operation(info, info->op_a);
			while (info->steps_b-- > 0)
				operation(info, info->op_b);
		}
	if (check_sorted(info->b, DEC) == FALSE)
	{
		max = find_min_max_elem(info->b, F_MAX);
		steps = get_steps(info->b, max);
		op = (get_pos(info->b, max) > get_mlen(info->b->size)) ? RRB : RB;
		while (steps-- > 0)
			operation(info, op);
	}
	while (info->b->size > 0)
		operation(info, PA);
}

void	sort(t_info *info)
{
	if (check_sorted(info->a, INC))
		return ;
	else if (info->a->size <= 3)
		sort_three(info, STACK_A);
	else if (info->a->size <= 10)
		sort_five(info);
	else
		sort_big(info);
}
