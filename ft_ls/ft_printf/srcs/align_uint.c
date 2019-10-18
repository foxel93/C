/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:31:06 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:26:27 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_print_flag(int *flags, size_t *p, int output)
{
	int		a;

	a = 0;
	if ((flags[0] & F_H) == F_H)
	{
		if (flags[4] == 'o' && flags[2] != 0 && output != 0)
		{
			ft_putchar_index('0', p, flags[9]);
			a = 1;
		}
		else if (flags[4] == 'x' && flags[2] != 0 && output != 0)
		{
			ft_putstr_index("0x", p, flags[9]);
			a = 2;
		}
		else if (flags[4] == 'X' && flags[2] != 0 && output != 0)
		{
			ft_putstr_index("0X", p, flags[9]);
			a = 2;
		}
	}
	return (a);
}

static void	ft_align_uint_left(unsigned long long output,
			int *flags, int len, size_t *p)
{
	int		len2;
	int		base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	len2 = ft_uint_perc_len(output, flags, base);
	flags[5] -= (len > len2) ? len : len2;
	ft_print_flag(flags, p, output);
	flags[6] = len;
	flags[7] = len2;
	ft_putnbr_unsign(output, flags, base, p);
	while (flags[5]-- > 0)
		ft_putchar_index(' ', p, flags[9]);
}

static void	ft_align_uint_right(unsigned long long output,
			int *flags, int len, size_t *p)
{
	int		len2;
	int		base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	len2 = ft_uint_perc_len(output, flags, base);
	flags[5] -= (len > len2) ? len : len2;
	flags[6] = len;
	flags[7] = len2;
	if (((flags[0] & F_Z) == F_Z && flags[2] < -1))
		ft_print_flag(flags, p, output);
	while (flags[5]-- > 0)
	{
		if (flags[2] > -2)
			ft_putchar_index(' ', p, flags[9]);
		else if ((flags[0] & F_Z) == F_Z)
			ft_putchar_index('0', p, flags[9]);
		else
			ft_putchar_index(' ', p, flags[9]);
	}
	if (((flags[0] & F_Z) == F_Z && flags[2] >= -1) || (flags[0] & F_Z) != F_Z)
		ft_print_flag(flags, p, output);
	ft_putnbr_unsign(output, flags, base, p);
}

void		ft_align_uint(unsigned long long output,
			int *flags, int len, size_t *p)
{
	(flags[0] & F_H && flags[4] == 'o' && flags[2] > 0) ? len++ : 0;
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	if ((flags[2] == -1 || flags[2] == 0) && output == 0)
	{
		if (flags[5] == 1)
			flags[5] = 0;
		while (flags[5]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
	}
	if ((flags[0] & F_M) == F_M)
		ft_align_uint_left(output, flags, len, p);
	else
		ft_align_uint_right(output, flags, len, p);
}
