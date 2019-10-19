#include "../../includes/push_swap.h"

int	swap_all(t_deque *a, t_deque *b)
{
	if (swap_stack(a) == 0)
		return (0);
	if (swap_stack(b) == 0)
	{
		swap_stack(a);
		return (0);
	}
	return (1);
}

int	rotate_all(t_deque *a, t_deque *b)
{
	if (rotate_stack(a))
		return (0);
	if (rotate_stack(b))
	{
		re_rotate_stack(a);
		return (0);
	}
	return (1);
}

int	re_rotate_all(t_deque *a, t_deque *b)
{
	if (re_rotate_stack(a))
		return (0);
	if (re_rotate_stack(b))
	{
		re_rotate_stack(a);
		return (0);
	}
	return (1);
}