/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:08:09 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:24:32 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putnbr_sign(long long n, int *flags, size_t *p)
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
	}
	else
		ft_putchar_index(n + '0', p, flags[9]);
}

void	ft_putnbr_double(long long n, int *flags, size_t *p)
{
	if (n >= 10)
	{
		ft_putnbr_double((n / 10ll), flags, p);
		ft_putnbr_double((n % 10ll), flags, p);
	}
	else
		ft_putchar_index(n + '0', p, flags[9]);
}

void	ft_putnbr_unsign(unsigned long long n, int *flags, int base, size_t *p)
{
	int	a;

	a = (base == 32) ? 2 : 1;
	(base == 32) ? base = 16 : 0;
	if (flags[7] > -1)
	{
		(base == 8 && (flags[0] & F_H)) ? flags[7]-- : 0;
		(base == 16 && (flags[0] & F_H)) ? flags[7] -= 2 : 0;
		while (flags[6]++ < flags[7])
			ft_putchar_index('0', p, flags[9]);
		flags[7] = -1;
	}
	if (n >= (unsigned long long)base)
	{
		ft_putnbr_unsign((n / base), flags, base * a, p);
		ft_putnbr_unsign((n % base), flags, base * a, p);
	}
	else
	{
		if (ft_isdigit((int)n + '0'))
			ft_putchar_index(n + '0', p, flags[9]);
		else if (base == 16)
			ft_print_hex(a, (int)n, flags, p);
	}
}
