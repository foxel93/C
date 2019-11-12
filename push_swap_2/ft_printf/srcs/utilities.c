/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:21:21 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:24:38 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_print_hex(int a, int n, int *flags, size_t *p)
{
	n < 0 ? n = -n : 0;
	if (a == 1)
		ft_putchar_index(n - 10 + 'a', p, flags[9]);
	if (a == 2)
		ft_putchar_index(n - 10 + 'A', p, flags[9]);
}

int		ft_print_bin(size_t const size, void const *const ptr,
		int *flags, size_t *p)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;
	char			sep;

	sep = 0;
	b = (unsigned char *)ptr;
	i = (int)size;
	flags[4] == 'b' ? ft_putstr_index("0b", p, flags[9]) : 0;
	flags[4] == 'B' ? ft_putstr_index("0B", p, flags[9]) : 0;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar_index((char)(byte + '0'), p, flags[9]);
		}
		(i != 0 && sep) ? ft_putchar_index(sep, p, flags[9]) : 0;
	}
	return (1);
}
