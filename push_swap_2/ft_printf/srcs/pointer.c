/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:05:17 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:25:35 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	ft_putnbr_address(unsigned long long n, int *flags, size_t *p)
{
	if (n >= (unsigned long long)16)
	{
		ft_putnbr_address((n / 16), flags, p);
		ft_putnbr_address((n % 16), flags, p);
	}
	else
	{
		if (ft_isdigit((int)n + '0'))
			ft_putchar_index(n + '0', p, flags[9]);
		else
			ft_print_hex(1, (int)n, flags, p);
	}
}

static void	ft_align_address(unsigned long address,
			int *flags, int len, size_t *p)
{
	char	c;

	if (flags[0] & F_M)
	{
		ft_putstr_index("0x", p, flags[9]);
		while (len - flags[6]++ > 0)
			ft_putchar_index('0', p, flags[9]);
		len != 0 ? ft_putnbr_address(address, flags, p) : 0;
		while (flags[5]--)
			ft_putchar_index(' ', p, flags[9]);
	}
	else
	{
		(flags[0] & F_Z) ? ft_putstr_index("0x", p, flags[9]) : 0;
		c = (flags[0] & F_Z) ? '0' : ' ';
		while (flags[5]--)
			ft_putchar_index(c, p, flags[9]);
		(!(flags[0] & F_Z)) ? ft_putstr_index("0x", p, flags[9]) : 0;
		while (len - flags[6]++ > 0)
			ft_putchar_index('0', p, flags[9]);
		(len != 0) ? ft_putnbr_address(address, flags, p) : 0;
	}
}

int			spec_pointer(va_list *args, int *flags, size_t *p)
{
	void			*output;
	unsigned long	address;
	int				len;

	output = va_arg(*args, void*);
	address = (unsigned long)output;
	len = ft_uint_length(address, flags, 16);
	flags[6] = len;
	flags[5] = (flags[1] > len) ? flags[1] : len + 2;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	if (flags[2] == -1 || flags[2] == 0)
	{
		flags[5]--;
		len = 0;
	}
	else if (flags[2] > len)
		len = flags[2];
	flags[5] -= (2 + len);
	flags[5] < 0 ? flags[5] = 0 : 0;
	ft_align_address(address, flags, len, p);
	return (1);
}
