#include "../includes/printf.h"

int ft_double_length(long double num, int flags[5])
{
	int len;
	long long left;

	len = 0;
	left = (int) (num);
	if ((num * ft_pow(10, flags[2])) < 0 || num == -0.0)
		len = 1;
	else if ((flags[0] & F_P) == F_P || (flags[0] & F_S) == F_S)
		len = 1;
	else if (num == 0.0)
		len = 1;
	if ((flags[0] & F_H) == F_H && flags[2] == 0)
		len++;
	while (left != 0)
	{
		left /= 10;
		len++;
	}
	len += flags[2];
	return (len);
}