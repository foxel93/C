/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:37:14 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 14:37:07 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		spec_signed(va_list *args, const int flags[5])
{
	if (flags[3] == (int)('h') + (int)('h'))
		return (print_hhd(args, flags));
	else if (flags[3] == (int)('l') + (int)('l'))
		return (print_lld(args, flags));
	else if (flags[3] == 'h')
		return (print_hd(args, flags));
	else if (flags[3] == 'l')
		return (print_ld(args, flags));
	else if (flags[3] == 'j')
		printf("jd- intmax_t");
	else if (flags[3] == 'z')
		printf("zd - size_t");
	else if (flags[3] == 't')
		printf("td - ptrdiff_t");
	else
		return (print_d(args, flags));
	return (1);
}

int		spec_unsigned(va_list *args, const int flags[5])
{
	if (flags[3] == (int)('h') + (int)('h'))
		return (print_hhu(args, flags));
	else if (flags[3] == (int)('l') + (int)('l'))
		return (print_llu(args, flags));
	else if (flags[3] == 'h')
		return (print_hu(args, flags));
	else if (flags[3] == 'l')
		return (print_lu(args, flags));
	else if (flags[3] == 'j')
		printf("jd- intmax_t");
	else if (flags[3] == 'z')
		printf("zd - size_t");
	else if (flags[3] == 't')
		printf("td - ptrdiff_t");
	else
		return (print_u(args, flags));
	return (1);
}

int		spec_float(va_list *args, const int flags[5])
{
	if (flags[3] == 'L')
	{
		ft_putstr("Here code");
	}
	return (1);
}
