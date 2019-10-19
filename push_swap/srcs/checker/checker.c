#include "../../includes/push_swap.h"

int 	checker(int argc, char **argv)
{
	if (argc == 1)
		ft_error(1);
	else if (argc - 1 != count_numbers(argc, argv))
		ft_error(0);
	return (0);
}
