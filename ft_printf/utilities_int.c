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

void	ft_putnbr_sign(long long n, int flag)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == LLONG_MIN)
		{
			ft_putchar('9');
			n %= 1000000000000000000LL;
		}
		n = -n;
	}
	else if ((flag & F_P) == F_P)
		ft_putchar('+');
	else if ((flag & F_S) == F_S)
		ft_putchar(' ');
	if (n >= 10)
	{
		ft_putnbr_sign((n / 10), 0);
		ft_putnbr_sign((n % 10), 0);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	ft_putnbr_unsign(long long n, int flag)
{
	if (n >= 10)
	{
		ft_putnbr_sign((n / 10), 0);
		ft_putnbr_sign((n % 10), 0);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void 	ft_allign_int(long long output, int flags, int width, int len)
{
	if ((flags & F_M) == F_M)
	{
		ft_putnbr_sign(output, flags);
		while (width != len)
		{
			ft_putchar(' ');
			width--;
		}
	}
	else
	{
		while (width != len)
		{
			if ((flags & F_Z) == F_Z)
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
		ft_putnbr_sign(output, flags);
	}
}

void 	ft_allign_uint(long long output, int flags, int width, int len)
{
	if ((flags & F_M) == F_M)
	{
		ft_putnbr_unsign(output, flags);
		while (width != len)
		{
			ft_putchar(' ');
			width--;
		}
	}
	else
	{
		while (width != len)
		{
			if ((flags & F_Z) == F_Z)
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
		ft_putnbr_unsign(output, flags);
	}
}