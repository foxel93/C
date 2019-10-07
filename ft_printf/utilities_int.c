/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:30:17 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 14:54:47 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_sign(long long n, int len, int len2)
{
	if (n < 0)
	{
		if (n == LLONG_MIN)
		{
			ft_putchar('9');
			n %= 1000000000000000000LL;
		}
		n = -n;
	}
    if (len2 > -1)
        while (len++ < len2)
            ft_putchar('0');
	if (n >= 10)
	{
		ft_putnbr_sign((n / 10), 0, 0);
		ft_putnbr_sign((n % 10), 0, 0);
	}
	else
		ft_putchar(n + '0');
}

void printBits(size_t const size, void const * const ptr, char sep)
{
    unsigned char *b;
    unsigned char byte;
    int i;
    int j;

    b = (unsigned char*) ptr;
    i = (int)size;
    while (--i >= 0)
    {
        j = 8;
        while (--j >= 0)
        {
            byte = (b[i] >> j) & 1;
            ft_putchar((char)(byte + '0'));
        }
        i != 0 ? ft_putchar(sep) : 0;
    }
}

long long	ft_pow(long long n, long pow)
{
    if (pow < 0)
        return (1);
    return (n * ft_pow(n, pow - 1));
}

int     ft_count(long long a)
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