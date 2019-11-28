/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:46:05 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/18 23:28:42 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_hhu(va_list *args, int *flags, size_t *p)
{
	int				len;
	unsigned char	output;
	int				base;
	int				l;

	base = (flags[4] == 'o' ? 8 : 10);
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned char)va_arg(*args, void*);
	l = (flags[2] == -1 || flags[2] == 0) && output == 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, flags, p));
	if ((ft_strchr("o", flags[4]) && l && !(flags[0] & F_H))
		|| (ft_strchr("xXu", flags[4]) && l))
	{
		while (flags[1]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
		return (1);
	}
	len = ft_uint_length(output, flags, base);
	ft_align_uint(output, flags, len, p);
	return (1);
}

int			print_hu(va_list *args, int *flags, size_t *p)
{
	int				len;
	unsigned short	output;
	int				base;
	int				l;

	base = (flags[4] == 'o' ? 8 : 10);
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned short)va_arg(*args, void*);
	l = (flags[2] == -1 || flags[2] == 0) && output == 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	if ((ft_strchr("o", flags[4]) && l && !(flags[0] & F_H))
		|| (ft_strchr("xXu", flags[4]) && l))
	{
		while (flags[1]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
		return (1);
	}
	len = ft_uint_length(output, flags, base);
	ft_align_uint(output, flags, len, p);
	return (1);
}

int			print_lu(va_list *args, int *flags, size_t *p)
{
	int				len;
	unsigned long	output;
	int				base;
	int				l;

	base = (flags[4] == 'o' ? 8 : 10);
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned long)va_arg(*args, void*);
	l = (flags[2] == -1 || flags[2] == 0) && output == 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	if ((ft_strchr("o", flags[4]) && l && !(flags[0] & F_H))
		|| (ft_strchr("xXu", flags[4]) && l))
	{
		while (flags[1]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
		return (1);
	}
	len = ft_uint_length(output, flags, base);
	ft_align_uint(output, flags, len, p);
	return (1);
}

int			print_llu(va_list *args, int *flags, size_t *p)
{
	int					len;
	unsigned long long	output;
	int					base;
	int					l;

	base = (flags[4] == 'o' ? 8 : 10);
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned long long)va_arg(*args, void*);
	l = (flags[2] == -1 || flags[2] == 0) && output == 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	if ((ft_strchr("o", flags[4]) && l && !(flags[0] & F_H))
		|| (ft_strchr("xXu", flags[4]) && l))
	{
		while (flags[1]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
		return (1);
	}
	len = ft_uint_length(output, flags, base);
	ft_align_uint(output, flags, len, p);
	return (1);
}

int			print_u(va_list *args, int *flags, size_t *p)
{
	int				len;
	unsigned int	output;
	int				base;
	int				l;

	base = (flags[4] == 'o' ? 8 : 10);
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned int)va_arg(*args, void*);
	l = (flags[2] == -1 || flags[2] == 0) && output == 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	if ((ft_strchr("o", flags[4]) && l && !(flags[0] & F_H))
		|| (ft_strchr("xXu", flags[4]) && l))
	{
		while (flags[1]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
		return (1);
	}
	len = ft_uint_length(output, flags, base);
	ft_align_uint(output, flags, len, p);
	return (1);
}
