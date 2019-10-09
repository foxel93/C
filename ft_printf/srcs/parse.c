/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:59:25 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 20:01:58 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int parse_string(const char **str, va_list *args, size_t *p, int fd)
{
	int flags[10];

	flags[0] = parse_flags(str);
	flags[1] = parse_width(str, args);
	flags[2] = parse_precision(str, args);
	((flags[3] = parse_modificators(str)) != 0) ? (*str)++ : 0;
	((flags[4] = parse_specificators(str)) != 0) ? (*str)++ : 0;
	flags[9] = fd;
	if (flags[4] == 'd')
		return (spec_signed(args, flags, p));
	else if (flags[4] == 'u' || flags[4] == 'o' || ft_tolower(flags[4]) == 'x'
			 || ft_tolower(flags[4]) == 'b')
		return (spec_unsigned(args, flags, p));
	else if (ft_tolower(flags[4]) == 'f' || ft_tolower(flags[4]) == 'e' ||
			 ft_tolower(flags[4]) == 'g' || ft_tolower(flags[4]) == 'a')
		return (spec_double(args, flags, p));
	else if (flags[4] == 'c')
		return (spec_char(args, flags, p));
	else if (flags[4] == 's')
		return (spec_string(args, flags, p));
	else if (flags[4] == 'p')
		return (spec_pointer(args, flags, p));
	else if (flags[4] == '%')
		return (spec_per(flags, p));
	return (0);
}
