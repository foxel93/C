/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:30:17 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 21:13:17 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int ft_putchar_index(char c, size_t *p, int fd)
{
	ft_putchar_fd(c, fd);
	(*p)++;
	return (0);
}

int ft_putstr_index(char *str, size_t *p, int fd)
{
	size_t i;

	i = 0;
	while (str[i] != 0)
		i++;
	*p += i;
	write(fd, str, i);
	return (0);
}

void ft_putnbr_sign(long long n, int *flags, size_t *p)
{
	if (n < 0)
	{
		if (n == LLONG_MIN)
		{
			ft_putchar_index('9', p, flags[9]);
			n %= 1000000000000000000LL;
		}
		n = -n;
	}
	if (flags[7] > -1)
	{
		while (flags[6]++ < flags[7])
			ft_putchar_index('0', p, flags[9]);
		flags[7] = -1;
	}
	if (n >= 10)
	{
		ft_putnbr_sign((n / 10), flags, p);
		ft_putnbr_sign((n % 10), flags, p);
	} else
		ft_putchar_index(n + '0', p, flags[9]);
}

int ft_print_bin(size_t const size, void const *const ptr, int *flags, size_t *p)
{
	unsigned char *b;
	unsigned char byte;
	int i;
	int j;
	char sep;

	sep = 0;
	b = (unsigned char *) ptr;
	i = (int) size;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar_index((char) (byte + '0'), p, flags[9]);
		}
		(i != 0 && sep) ? ft_putchar_index(sep, p, flags[9]) : 0;
	}
	return (1);
}

long long ft_pow(long long n, long pow)
{
	if (pow < 0)
		return (1);
	return (n * ft_pow(n, pow - 1));
}

int ft_count(long long a)
{
	int count;

	count = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		count++;
		a /= 10;
	}
	return (count);
}