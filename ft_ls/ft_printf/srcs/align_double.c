/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:26:24 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:26:03 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_printf_double(long long left, long long right,
				int *flags, size_t *p)
{
	int			r;
	long long	tmp;

	r = ft_count(right);
	tmp = (left < 0) ? -left : left;
	ft_putnbr_double(tmp, flags, p);
	if ((flags[5] == 0 && flags[0] & F_H) || flags[5] != 0)
	{
		ft_putchar_index('.', p, flags[9]);
		if (flags[2] != 0 && flags[2] != -1)
		{
			while (flags[2] - r++ > 0)
				ft_putchar_index('0', p, flags[9]);
			ft_putnbr_double(right, flags, p);
		}
	}
}

static int		ft_print_flag(long long left, const int *flags, size_t *p)
{
	if (left < 0)
	{
		ft_putchar_index('-', p, flags[9]);
		return (1);
	}
	else if ((flags[0] & F_P) == F_P)
	{
		ft_putchar_index('+', p, flags[9]);
		return (1);
	}
	else if ((flags[0] & F_S) == F_S)
	{
		ft_putchar_index(' ', p, flags[9]);
		return (1);
	}
	return (0);
}

static void		ft_align_double_left(long long left, long long right,
				int *flags, size_t *p)
{
	int		left_len;
	int		right_len;
	int		len_num;
	int		width;
	char	c;

	left_len = ft_count(left);
	right_len = (flags[2] == -1) ? 0 : flags[2];
	len_num = left_len + right_len;
	(left < 0 || flags[0] & F_P || flags[0] & F_S) ? len_num++ : 0;
	((right_len == 0 && flags[0] & F_H) || right_len != 0) ? len_num++ : 0;
	width = flags[1] > len_num ? flags[1] : len_num;
	ft_print_flag(left, flags, p);
	c = (flags[0] & F_Z) ? '0' : ' ';
	flags[5] = right_len;
	ft_printf_double(left, right, flags, p);
	while (width-- > len_num)
		ft_putchar_index(c, p, flags[9]);
}

static void		ft_align_double_right(long long left, long long right,
				int *flags, size_t *p)
{
	int		left_len;
	int		right_len;
	int		len_num;
	int		width;
	char	c;

	left_len = ft_count(left);
	right_len = (flags[2] == -1) ? 0 : flags[2];
	len_num = left_len + right_len;
	(left < 0 || flags[0] & F_P || flags[0] & F_S) ? len_num++ : 0;
	((right_len == 0 && flags[0] & F_H) || right_len != 0) ? len_num++ : 0;
	width = flags[1] > len_num ? flags[1] : len_num;
	(flags[0] & F_Z) ? width -= ft_print_flag(left, flags, p) : 0;
	c = (flags[0] & F_Z) ? '0' : ' ';
	while (width-- > len_num)
		ft_putchar_index(c, p, flags[9]);
	flags[5] = right_len;
	(!(flags[0] & F_Z)) ? ft_print_flag(left, flags, p) : 0;
	ft_printf_double(left, right, flags, p);
}

void			ft_align_double(long long left, long long right,
				int *flags, size_t *p)
{
	if (flags[0] & F_M)
		ft_align_double_left(left, right, flags, p);
	else
		ft_align_double_right(left, right, flags, p);
}
