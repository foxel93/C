#include "../../includes/push_swap.h"

void 	swap_stack(t_deque *d)
{
	t_val tmp;
	t_val tmp2;

	tmp = deque_pop_back(d);
	tmp2 = deque_peek_back(d);
	d->info->tail->val = tmp;
	deque_push_back(d, tmp2);
}