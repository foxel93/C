#include "../includes/push_swap.h"

int 	max_len_deq(t_deque *a, t_deque *b)
{
	int len_a;
	int len_b;

	len_a = (int)(a->info->len) - 1;
	len_b = (int)(b->info->len) - 1;
	return (len_a > len_b) ? len_a : len_b;
}

void	ft_print_stacks(t_deque *a, t_deque *b, int max)
{
	size_t len_a;
	size_t len_b;

	len_a = a->info->len - 1;
	len_b = b->info->len - 1;

	while (max > len_a && max > len_b)
	{
		ft_printf("|\t\t\t\t|\n");
		max--;
	}
	while (len_a > 0 || len_b > 0)
	{
		if (len_a > len_b)
		{
			ft_printf("|\t%d\t\t\t|\n",deque_peek_back_n(a, len_a));
			len_a--;
		}
		else if (len_a < len_b)
		{
			ft_printf("|\t\t\t%d\t|\n",deque_peek_back_n(b, len_b));
			len_b--;
		}
		else
		{
			ft_printf("|\t%d\t\t%d\t|\n",deque_peek_back_n(a, len_a), deque_peek_back_n(b, len_b));
			len_a--;
			len_b--;
		}
	}
	ft_printf("|\t~\t\t~\t|\n");
	ft_printf("|\ta\t\tb\t|\n");
	ft_printf("-----------------\n");
}
