/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:27:39 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:25:05 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_hhd(va_list *args, int *flags, size_t *p)
{
	int		len;
	char	output;

	output = (char)va_arg(*args, void*);
	len = ft_int_length(output, flags);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	(output == 0 && (flags[0] & F_P || flags[0] & F_S)) ? flags[5]-- : 0;
	ft_align_int(output, flags, len, p);
	return (1);
}

int			print_hd(va_list *args, int *flags, size_t *p)
{
	int		len;
	short	output;

	output = (short)va_arg(*args, void*);
	len = ft_int_length(output, flags);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	(output == 0 && (flags[0] & F_P || flags[0] & F_S)) ? flags[5]-- : 0;
	ft_align_int(output, flags, len, p);
	return (1);
}

int			print_ld(va_list *args, int *flags, size_t *p)
{
	int		len;
	long	output;

	output = (long)va_arg(*args, void*);
	len = ft_int_length(output, flags);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	(output == 0 && (flags[0] & F_P || flags[0] & F_S)) ? flags[5]-- : 0;
	ft_align_int(output, flags, len, p);
	return (1);
}

int			print_lld(va_list *args, int *flags, size_t *p)
{
	int			len;
	long long	output;

	output = (long long)va_arg(*args, void*);
	len = ft_int_length(output, flags);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	(output == 0 && (flags[0] & F_P || flags[0] & F_S)) ? flags[5]-- : 0;
	ft_align_int(output, flags, len, p);
	return (1);
}

int			print_d(va_list *args, int *flags, size_t *p)
{
	int		len;
	int		output;

	output = (int)va_arg(*args, void*);
	len = ft_int_length(output, flags);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	(output == 0 && (flags[0] & F_P || flags[0] & F_S)) ? flags[5]-- : 0;
	ft_align_int(output, flags, len, p);
	return (1);
}
