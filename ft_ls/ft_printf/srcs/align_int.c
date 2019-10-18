/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:29:35 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:26:16 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_print_flag(long long output, int *flags, size_t *p)
{
	int		a;

	a = 0;
	if (output < 0)
	{
		ft_putchar_index('-', p, flags[9]);
		a++;
	}
	else if ((flags[0] & F_P) == F_P)
	{
		ft_putchar_index('+', p, flags[9]);
		a++;
	}
	else if ((flags[0] & F_S) == F_S)
	{
		ft_putchar_index(' ', p, flags[9]);
		a++;
	}
	return (a);
}

static void	ft_align_int_left(long long output, int *flags, int len, size_t *p)
{
	int		len2;

	len2 = ft_int_perc_len(output, flags);
	flags[5] -= (len > len2) ? len : len2;
	ft_print_flag(output, flags, p);
	flags[6] = len;
	flags[7] = len2;
	ft_putnbr_sign(output, flags, p);
	while (flags[5] > 0)
	{
		ft_putchar_index(' ', p, flags[9]);
		flags[5]--;
	}
}

static void	ft_align_int_right(long long output, int *flags, int len, size_t *p)
{
	int		len2;

	len2 = ft_int_perc_len(output, flags);
	flags[5] -= (len > len2) ? len : len2;
	if ((flags[0] & F_Z) == F_Z)
		ft_print_flag(output, flags, p);
	while (flags[5]-- > 0)
	{
		if (flags[2] > -2)
			ft_putchar_index(' ', p, flags[9]);
		else if ((flags[0] & F_Z) == F_Z)
			ft_putchar_index('0', p, flags[9]);
		else
			ft_putchar_index(' ', p, flags[9]);
	}
	if ((flags[0] & F_Z) != F_Z)
		ft_print_flag(output, flags, p);
	flags[6] = len;
	flags[7] = len2;
	ft_putnbr_sign(output, flags, p);
}

void		ft_align_int(long long output, int *flags, int len, size_t *p)
{
	if ((flags[2] == -1 || flags[2] == 0) && output == 0)
	{
		if (flags[5] == 1)
			flags[5] = 0;
		while (flags[5]--)
			ft_putchar_index(' ', p, flags[9]);
	}
	else if ((flags[0] & F_M) == F_M)
		ft_align_int_left(output, flags, len, p);
	else
		ft_align_int_right(output, flags, len, p);
}
