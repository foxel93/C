#include "../includes/push_swap.h"

void	start(t_deque *a, t_deque *b, int count)
{
	t_deque *com;
	t_val 	max;
	t_val 	min;
	int i;
	t_val tmp;

	min = INT_MAX;
	max = INT_MIN;
	i = 0;
	while (i < count)
	{
		tmp = deque_peek_back_n(a, i + 1);
		tmp > max ? max = tmp : 0;
		tmp < min ? min = tmp : 0;
		i++;
	}
	ft_printf("%d\t%d\n",min, max);
	if (!(com =  deque_alloc())) {
		deque_free(a);
		deque_free(b);
		ft_error(0);
	}
	//qs(a, b, com);
	ft_print_stacks(a, b, count);
	ft_print_commands(com);
}

int main(int argc, char **argv)
{
	int *n;
	t_deque *a;
	t_deque *b;
	int count;
	int i;

	count = count_numbers(argc, argv);
	n = all_numbers(argc, argv, count);
	a = deque_alloc();
	b = deque_alloc();
	if (!a || !b)
	{
		b ? deque_free(b) : 0;
		a ? deque_free(a) : 0;
		free(n);
		ft_error(0);
	}
	i = 0;
	while (i < count)
		(deque_push_back(a, n[i])) ? i++ : 0;
	free(n);
	start(a, b, count);
	deque_free(a);
	deque_free(b);
	return (0);
}