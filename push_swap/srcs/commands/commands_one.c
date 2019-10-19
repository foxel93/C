#include "../../includes/push_swap.h"

int 	swap_stack(t_deque *d)
{
	t_val tmp;
	t_val tmp2;

	if (d->info->len < 3)
		return (0);
	tmp = deque_pop_back(d);
	tmp2 = deque_peek_back(d);
	d->info->tail->val = tmp;
	deque_push_back(d, tmp2);
	return (1);
}

int 	rotate_stack(t_deque *d)
{
	t_val tmp;

	if (d->info->len < 3)
		return (0);
	tmp = deque_pop_back(d);
	deque_push_front(d, tmp);
	return (1);
}

int 	re_rotate_stack(t_deque *d)
{
	t_val tmp;

	if (d->info->len < 3)
		return (0);
	tmp = deque_pop_front(d);
	deque_push_back(d, tmp);
	return (1);
}

int 	replace_top(t_deque *src, t_deque *dst)
{
	t_val tmp;

	if (deque_is_empty(src))
		return (0);
	tmp = deque_pop_back(src);
	deque_push_back(dst, tmp);
	return (1);
}