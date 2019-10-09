/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:37:14 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 20:01:58 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int spec_signed(va_list *args, int *flags, size_t *p)
{
	if (flags[3] == (int) ('h') + (int) ('h'))
		return (print_hhd(args, flags, p));
	else if (flags[3] == (int) ('l') + (int) ('l'))
		return (print_lld(args, flags, p));
	else if (flags[3] == 'h')
		return (print_hd(args, flags, p));
	else if (flags[3] == 'l')
		return (print_ld(args, flags, p));
	else if (flags[3] == 'z')
		return (print_z(args, flags, p));
	else if (flags[3] == 0)
		return (print_d(args, flags, p));
	return (0);
}

int spec_unsigned(va_list *args, int *flags, size_t *p)
{
	if (flags[3] == (int) ('h') + (int) ('h'))
		return (print_hhu(args, flags, p));
	else if (flags[3] == (int) ('l') + (int) ('l'))
		return (print_llu(args, flags, p));
	else if (flags[3] == 'h')
		return (print_hu(args, flags, p));
	else if (flags[3] == 'l')
		return (print_lu(args, flags, p));
	else if (flags[3] == 'z')
		return (print_zu(args, flags, p));
	else if (flags[3] == 0)
		return (print_u(args, flags, p));
	return (0);
}

int spec_double(va_list *args, int *flags, size_t *p)
{
	if (flags[3] == 'L' || flags[3] == 'l')
	{
		return (print_ldouble(args, flags, p));
	} else if (flags[3] == 0)
	{
		return (print_double(args, flags, p));
	}
	return (0);
}
