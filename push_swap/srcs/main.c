#include "push_swap.h"

int main(int argc, char **argv)
{
	t_deque *a;
	t_deque *b;
	int	max;


	if(!(a = deque_alloc()))
		ft_error(0);
	if(!(b = deque_alloc()))
	{
		deque_free(a);
		ft_error(0);
	}

	for (int i = 1; i <= 512; i+=i)
	{
		deque_push_back(a, i);
	}

	for (int i = 1; i <= 64; i+=i)
	{
		deque_push_back(b, i);
	}
	swap_stack(a);
	//deque_pop_front(a);
	//deque_pop_front(a);
	//deque_pop_back(a);
	//deque_pop_back(a);
	//ft_printf("%d\n",deque_peek_front_n(a, 10));

	/*while (!deque_is_empty(a))
	{
		ft_printf("%d\t%d\n", deque_pop_back(a), a->info->len);
		//ft_printf("%d\t%d\n", deque_pop_back(a), a->info->len);
	}*/
	max = max_len_deq(a,b);
	ft_print_stacks(a,b,max);
	deque_free(a);
	deque_free(b);
	return 0;
}