#include "../includes/push_swap.h"

void ft_error(int n_error)
{
	if (n_error == 4)
	{
		ft_putstr("OK");
		exit(EXIT_SUCCESS);
	}
	else if (n_error == 0)
		ft_putstr_fd("Error", 2);
	else if (n_error == 1)
	{
		ft_putstr("Usage: checker [-v] [-t] [-s <partial SDK name>][-b <bundle identifier>] [-a <application>] [filenames] [--args arguments]\n");
		ft_putstr("Options:\n");
		ft_putstr("\t\t-a\t\t\tOpens with the specified application.\n");
	}
	else if (n_error == 2)
	{
		ft_putstr("Usage: push_swap [-v] [-t] [-s <partial SDK name>][-b <bundle identifier>] [-a <application>] [filenames] [--args arguments]\n");
		ft_putstr("Options:\n");
		ft_putstr("\t\t-a\t\t\tOpens with the specified application.\n");
	}
	else if (n_error == 3)
		ft_putstr("KO");
	exit(EXIT_FAILURE);
}