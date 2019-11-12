#include "push_swap.h"

size_t find_min_max_index(t_stack *stack, size_t min_max)
{
	int i;
	t_val tmp;
	int index;

	if (stack->size == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = get_val(stack, 0);
	while (++i < stack->size)
	{
		if ((tmp < get_val(stack, i) && min_max == F_MAX) ||
			(tmp > get_val(stack, i) && min_max == F_MIN))
		{
			tmp = get_val(stack, i);
			index = i;
		}
	}
	return (index);
}

t_val 	find_min_max_elem(t_stack *stack, size_t min_max)
{
	int i;
	t_val tmp;

	if (stack->size == 0)
		return (0);
	i = 0;
	tmp = get_val(stack, 0);
	while (++i < stack->size)
	{
		if ((tmp < get_val(stack, i) && min_max == F_MAX) ||
			(tmp > get_val(stack, i) && min_max == F_MIN))
			tmp = get_val(stack, i);
	}
	return (tmp);
}

size_t	get_pos(t_stack *stack, int value)
{
	size_t i;

	i = -1;
	while (++i < stack->size)
	{
		if (get_val(stack, i) == value)
			break ;
	}
	return (i + 1);
}

size_t	get_mlen(int length)
{
	return (length / 2 + ((length % 2) == 1 ? 1 : 0));
}

t_val get_val(t_stack *stack, size_t pos)
{
	ssize_t new_pos;

	new_pos = (ssize_t)stack->size - 1 - pos;
	if (new_pos < 0)
		return (0);
	return (get_nth_elem(stack, new_pos)->value);
}