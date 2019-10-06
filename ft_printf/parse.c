/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:59:25 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 10:59:28 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parse_string(const char **str, va_list *args)
{
	int	flags[5];

	flags[0] = parse_flags(str);
	flags[1] = parse_width(str, args);
	flags[2] = parse_precision(str, args);
	((flags[3] = parse_modificators(str)) != 0) ? (*str)++ : 0;
	((flags[4] = parse_specificators(str)) != 0) ? (*str)++ : 0;
	if (flags[4] == 'd')
		return (spec_signed(args, flags));
	else if (flags[4] == 'u' || flags[4] == 'o'|| ft_tolower(flags[4]) == 'X')
		return (spec_unsigned(args, flags));
	else if (ft_tolower(flags[4]) == 'F' || ft_tolower(flags[4]) == 'E' ||
            ft_tolower(flags[4]) == 'G' || ft_tolower(flags[4]) == 'A')
		return (spec_float(args, flags));
	else if (flags[4] == 'c')
		return (spec_char(args, flags));
	else if (flags[4] == 's')
		return (spec_string(args, flags));
	else if (flags[4] == 'p')
		return (spec_pointer(args, flags));
	else if (flags[4] == '%')
		return (spec_per());
	return (0);
}
