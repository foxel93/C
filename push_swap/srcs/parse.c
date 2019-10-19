#include "../includes/push_swap.h"

static void clean_n(t_val *n, int n_error)
{
	free(n);
	ft_error(n_error);
}

int	count_numbers(int argc, char **argv)
{
	int		i;
	int 	j;
	int 	N;

	N = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] && ft_isspace(argv[i][j]))
			j++;
		if ((argv[i][j] == '-' || argv[i][j] == '+'))
			(!ft_isdigit(argv[i][j + 1])) ? ft_error(0) : ++j;
		else if (argv[i][j] == 0 && ++i)
		{
			j = 0;
			continue;
		}
		(ft_isdigit(argv[i][j])) ? N++ : 0;
		while (argv[i][j] && ft_isdigit(argv[i][j]))
			j++;
	}
	return (N);
}

static long	get_number(int *argc, char **argv, int *j, int *i)
{
	long	a;
	int 	sign;

	a = 0;
	sign = 1;
	while (*i < *argc)
	{
		while (argv[*i][*j] && ft_isspace(argv[*i][*j]) && (*j)++);
		if ((argv[*i][*j] == '+') || (argv[*i][*j] == '-'))
		{
			(argv[*i][*j] == '-') ? sign = -1 : 0;
			(!ft_isdigit(argv[*i][*j + 1])) ? ft_error(0) : ++(*j);
		}
		else if (argv[*i][*j] == 0 && ++(*i))
		{
			*j = 0;
			continue;
		}
		while (argv[*i][*j] && ft_isdigit(argv[*i][*j]) && a <= INT_MAX && a >= INT_MIN)
			a = a * 10 + sign * (argv[*i][(*j)++] - '0');
		(a > INT_MAX || a < INT_MIN) ? a = INT_MAX + 1L : 0;
		return (a);
	}
	return (0);
}

int *all_numbers(int argc, char **argv, int count)
{
	t_val	*n;
	int 	c;
	int 	i;
	int		j;
	long 	t;

	j = 0;
	i = 1;
	c = -1;
	if (!(n = malloc(sizeof(t_val) * count)))
		ft_error(0);
	while (++c < count)
		if ((t = get_number(&argc, argv, &j, &i)) == INT_MAX + 1L)
			clean_n(n, 0);
		else
			n[c] = (int)t;
	i = -1;
	while (++i < count - 1 && (j = i + 1))
		while (j < count)
			if (n[i] == n[j++])
				clean_n(n, 0);
	return (n);
}