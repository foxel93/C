/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:27 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 15:49:07 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_int_length(ssize_t num, int *flags)
{
	int	len;

	len = 0;
	flags[8] = 0;
	if (num < 0 || (flags[0] & F_P) == F_P || (flags[0] & F_S) == F_S)
		len = 1;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int		ft_uint_length(size_t num, int *flags, int base)
{
	int	len;

	len = 0;
	flags[8] = 0;
	base == 32 ? base = 16 : 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

int		ft_uint_perc_len(size_t num, int *flags, int base)
{
	int	len;
	int	s;

	s = 0;
	len = 0;
	base == 32 ? base = 16 : 0;
	flags[8] = 0;
	if (((flags[0] & F_H) == F_H) && base == 8 && num != 0)
		s = 1;
	if (((flags[0] & F_H) == F_H) && base == 16)
		s = 2;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	if (flags[2] > len)
		len = flags[2];
	return (len + s);
}

int		ft_int_perc_len(ssize_t num, int *flags)
{
	int	len;
	int	s;

	len = 0;
	s = 0;
	flags[8] = 0;
	if (num < 0 || (flags[0] & F_P) == F_P || (flags[0] & F_S) == F_S)
		s = 1;
	else if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	if (flags[2] > len)
		len = flags[2];
	return (len + s);
}
