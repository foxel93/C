#include "push_swap.h"

static t_val	get_prev_big(t_stack *stack, int value)
{
	size_t	i;
	t_val	prev_big;
	t_val	tmp;

	if (find_min_max_elem(stack, F_MIN) < value)
	{
		prev_big = MIN_VAL;
		i = -1;
		while (++i < stack->size)
		{
			tmp = get_val(stack, i);
			if ((prev_big < tmp) && (tmp < value))
				prev_big = tmp;
		}
	}
	else
		prev_big = find_min_max_elem(stack, F_MAX);
	return (prev_big);
}

size_t	get_steps(t_stack *stack, int value)
{
	size_t			midlen;
	size_t			pos;

	midlen = get_mlen(stack->size);
	pos = get_pos(stack, value);
	return ((pos > midlen) ? (stack->size - pos) + 1 : pos - 1);
}

void	get_min_steps(t_info *info)
{
	size_t			min_steps;
	t_val			min_steps_val;
	size_t			current_steps;
	t_val			prev_big;
	size_t 			i;

	min_steps_val = get_val(info->a, 0);
	min_steps = get_steps(info->a, min_steps_val);
	min_steps += get_steps(info->b, get_prev_big(info->b, min_steps_val));
	i = -1;
	while (++i < info->a->size)
	{
		prev_big = get_prev_big(info->b, get_val(info->a, i));
		current_steps = get_steps(info->a, get_val(info->a, i));
		current_steps += get_steps(info->b, prev_big);
		(current_steps < min_steps) ? min_steps_val = get_val(info->a, i) : 0;
		(current_steps < min_steps) ? min_steps = current_steps : 0;
	}
	info->pos_a = get_pos(info->a, min_steps_val);
	info->steps_a = get_steps(info->a, min_steps_val);
	info->steps_b = get_steps(info->b, get_prev_big(info->b, min_steps_val));
	info->total_steps = min_steps;
	info->pos_prev_big = get_pos(info->b, get_prev_big(info->b, min_steps_val));
	info->op_a = (info->pos_a > get_mlen(info->a->size)) ? RRA : RA;
	info->op_b = (info->pos_prev_big > get_mlen(info->b->size)) ? RRB : RB;
}

