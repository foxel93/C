/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:16:55 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:24:56 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_z(va_list *args, int *flags, size_t *p)
{
	int		len;
	size_t	output;

	output = (size_t)va_arg(*args, void*);
	len = ft_uint_length(output, flags, 10);
	ft_align_uint(output, flags, len, p);
	return (1);
}

int		print_zu(va_list *args, int *flags, size_t *p)
{
	int		len;
	ssize_t	output;

	output = (ssize_t)va_arg(*args, void*);
	len = ft_int_length(output, flags);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	(output == 0 && (flags[0] & F_P || flags[0] & F_S)) ? flags[5]-- : 0;
	ft_align_int(output, flags, len, p);
	return (1);
}
