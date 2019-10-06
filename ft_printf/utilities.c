/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:56:41 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 14:30:07 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_putadr(unsigned long n, int *p)
{
	if (n > 15)
	{
		ft_putadr((n / 16), p);
		ft_putadr((n % 16), p);
	}
	else if (n < 10)
	{
		(*p)++;
		ft_putchar((char)(n + '0'));
	}
	else
	{
		(*p)++;
		n == 10 ? ft_putchar('a') : 0;
		n == 11 ? ft_putchar('b') : 0;
		n == 12 ? ft_putchar('c') : 0;
		n == 13 ? ft_putchar('d') : 0;
		n == 14 ? ft_putchar('e') : 0;
		n == 15 ? ft_putchar('f') : 0;
	}
}

size_t ft_int_length(ssize_t num, int flag)
{
	size_t len;
	int sign;

	len = 0;
	if (num < 0 || (flag & F_P) == F_P || (flag & F_S) == F_S)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	print_flags(const int flags[5])
{
	if (flags[0] != 0)
		printf("f:");
	if ((flags[0] & F_H) == F_H)
		printf("#");
	if ((flags[0] & F_M) == F_M)
		printf("-");
	if ((flags[0] & F_P) == F_P)
		printf("+");
	if ((flags[0] & F_S) == F_S)
		printf(" ");
	if ((flags[0] & F_Z) == F_Z)
		printf("0");
	if (flags[1] == -1)
		printf("");
	if (flags[1] > -1)
		printf(" %d",flags[1]);
	if (flags[2] == -2)
		printf("");
	if (flags[2] == -1)
		printf(" .");
	if (flags[2] > -1)
		printf(" .%d",flags[2]);
}