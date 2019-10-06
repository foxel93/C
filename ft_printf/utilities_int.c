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