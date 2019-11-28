double	ft_pow(double num, int e)
{
	int		i;
	double	res;

	res = 1;
	i = -1;
	while (++i < e)
		res *= num;
	return (res);
}
