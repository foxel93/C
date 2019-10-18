#include "../includes/push_swap.h"

int ft_error(int n_error)
{
	if (n_error == 0)
	{
		ft_putstr_fd("Error", 2);
		exit(0);
	}
	return (1);
}