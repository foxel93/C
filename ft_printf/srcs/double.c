#include "../includes/printf.h"

static long long            ft_right_double(int *flags, long double n)
{
	long long       tmp;
	int         	len;
	long double     decimal;
	long long       value;

	if (flags[2] == -2)
		flags[2] = 6;
	len = (flags[2] > 0) ? 1 : 0;

	tmp = (long long)(n < 0 ? -n : n);
	while (tmp && ++len)
		tmp /= 10;

	decimal = ((n < 0.0l) ? -n : n);
	decimal = (decimal - (long long)(((n < 0.0l) ? -n : n))) * ft_pow(10, flags[2]);
	decimal = ((long long)decimal % 10ll > 4) ? (decimal) / 10ll + 1l : decimal / 10ll;
	value = (long long)decimal;
	return (value);
}

static long long            ft_left_double(int *flags, long double n)
{
	long long left;

	flags[8] = 0;
	left = (long long) n;
	return (left);
}

int print_ldouble(va_list *args, int *flags, size_t *p)
{
	long double output;
	long long left;
	long long right;

	output = (long double) va_arg(*args, long double);
	ft_right_double(flags, output);
	if (!ft_isnan(output, flags, p) || !ft_isplus_inf(output, flags, p)
		|| !ft_isminus_inf(output, flags, p))
		return (1);
	left = ft_left_double(flags, output);
	right = ft_right_double(flags, output);

	ft_align_double(left, right, flags, p);

	return (1);
}

int print_double(va_list *args, int *flags, size_t *p)
{
	long double output;
	long long left;
	long long right;

	output = (double) va_arg(*args, double);
	if (!ft_isnan(output, flags, p) || !ft_isplus_inf(output, flags, p)
		|| !ft_isminus_inf(output, flags, p))
		return (1);
	ft_right_double(flags, output);
	if (!ft_isnan(output, flags, p) || !ft_isplus_inf(output, flags, p)
		|| !ft_isminus_inf(output, flags, p))
		return (1);
	left = ft_left_double(flags, output);
	right = ft_right_double(flags, output);

	ft_align_double(left, right, flags, p);
	return (1);
}

