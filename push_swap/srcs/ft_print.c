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

void	ft_print_commands(t_deque *a)
{
	size_t	len_a;
	int		l;
	char 	*str;

	len_a = a->info->len - 1;
	while (len_a > 0)
	{
		str = "";
		l = deque_peek_back_n(a, len_a);
		l == 1 ? str = "sa" : 0;
		l == 2 ? str = "sb" : 0;
		l == 3 ? str = "ss" : 0;
		l == 4 ? str = "ra" : 0;
		l == 5 ? str = "rb" : 0;
		l == 6 ? str = "rr" : 0;
		l == 7 ? str = "rra" : 0;
		l == 8 ? str = "rrb" : 0;
		l == 9 ? str = "rrr" : 0;
		l == 10 ? str = "pa" : 0;
		l == 11 ? str = "pb" : 0;
		ft_printf("%s\n",str);
		len_a--;
	}
}
