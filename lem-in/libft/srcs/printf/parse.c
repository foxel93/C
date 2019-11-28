/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:59:25 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:35:53 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		parse_string(const char **str, va_list *args, size_t *p, int fd)
{
	int	flags[10];

	flags[9] = fd;
	flags[0] = parse_flags(str);
	flags[1] = parse_width(str, args, flags);
	(flags[1] >= 0 && ft_isdigit(**str)) ? flags[1] = ft_atoi((*str)++) : 0;
	flags[2] = parse_precision(str, args);
	((flags[3] = parse_modificators(str)) != 0) ? (*str)++ : 0;
	((flags[4] = parse_specificators(str)) != 0) ? (*str)++ : 0;
	if (flags[4] == 'd')
		return (spec_signed(args, flags, p));
	else if (flags[4] != 0 && ft_strchr("uoxXbB", flags[4]))
		return (spec_unsigned(args, flags, p));
	else if (flags[4] != 0 && ft_strchr("fF", flags[4]))
		return (spec_double(args, flags, p));
	else if (flags[4] == 'c')
		return (spec_char(args, flags, p));
	else if (flags[4] == 's')
		return (spec_string(args, flags, p));
	else if (flags[4] == 'p')
		return (spec_pointer(args, flags, p));
	else if (flags[4] == '%')
		return (spec_per(flags, p));
	ft_putstr_index((char *)*str, p, flags[9]);
	return (0);
}

int		spec_per(int *flags, size_t *p)
{
	if ((flags[0] & F_M) == F_M)
		ft_putchar_index('%', p, flags[9]);
	while (flags[1]-- > 1)
	{
		if (flags[0] & F_Z)
			ft_putchar_index('0', p, flags[9]);
		else
			ft_putchar_index(' ', p, flags[9]);
	}
	if ((flags[0] & F_M) != F_M)
		ft_putchar_index('%', p, flags[9]);
	return (1);
}

int		spec_char(va_list *args, int *flags, size_t *p)
{
	unsigned char	output;
	int				width;
	char			c;

	output = (unsigned char)va_arg(*args, int);
	if (flags[1] > 0)
		width = flags[1] - 1;
	else
		width = 0;
	if (flags[0] & F_M)
	{
		write(flags[9], &output, 1);
		(*p)++;
		while (width--)
			ft_putchar_index(' ', p, flags[9]);
	}
	else
	{
		c = (flags[0] & F_Z) ? '0' : ' ';
		while (width--)
			ft_putchar_index(c, p, flags[9]);
		write(flags[9], &output, 1);
		(*p)++;
	}
	return (1);
}
