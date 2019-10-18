/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:02:13 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 15:45:09 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			parse_width(const char **str, va_list *arg, int *flags)
{
	long	a;
	long	b;

	a = 0;
	if (**str == '*')
	{
		(*str)++;
		b = va_arg(*arg, int);
		if (b < 0)
		{
			flags[0] |= F_M;
			return ((int)(-b));
		}
		else
			return ((int)b);
	}
	if (!ft_isdigit(**str))
		return (-1);
	while (ft_isdigit(**str) && a < INT_MAX)
		a = a * 10 + (*((*str)++) - '0');
	if (a > INT_MAX)
		return (0);
	return ((int)a);
}

int			parse_precision(const char **str, va_list *arg)
{
	long	b;
	long	a;

	if (**str == '.')
	{
		(*str)++;
		a = 0;
		if (**str == '*')
		{
			(*str)++;
			b = va_arg(*arg, int);
			if (b < 0)
				return (-2);
			else
				return ((int)b);
		}
		if (!ft_isdigit(**str))
			return (-1);
		while (ft_isdigit(**str) && a < INT_MAX)
			a = a * 10 + (*((*str)++) - '0');
		if (a > INT_MAX)
			return (0);
		return ((int)a);
	}
	return (-2);
}

int			parse_modificators(const char **str)
{
	int		mod;

	mod = 0;
	if (**str == 'h' && *((*str) + 1) == 'h')
	{
		(*str)++;
		return ((int)'h' + (int)'h');
	}
	if (**str == 'l' && *((*str) + 1) == 'l')
	{
		(*str)++;
		return ((int)'l' + (int)'l');
	}
	**str == 'h' ? mod = 'h' : 0;
	**str == 'l' ? mod = 'l' : 0;
	**str == 'L' ? mod = 'L' : 0;
	**str == 'q' ? mod = 'q' : 0;
	**str == 'j' ? mod = 'j' : 0;
	**str == 'z' ? mod = 'z' : 0;
	**str == 't' ? mod = 't' : 0;
	return (mod);
}

int			parse_flags(const char **str)
{
	int		flag;

	flag = 0;
	while (*(++(*str)))
	{
		**str == '#' ? flag |= F_H : 0;
		**str == '0' ? flag |= F_Z : 0;
		**str == '-' ? flag |= F_M : 0;
		**str == ' ' ? flag |= F_S : 0;
		**str == '+' ? flag |= F_P : 0;
		if (!ft_strchr("#0- +", **str))
			break ;
	}
	(flag && (flag & F_M) && (flag & F_Z)) ? flag -= F_Z : 0;
	(flag && (flag & F_P) && (flag & F_S)) ? flag -= F_S : 0;
	return (flag);
}

int			parse_specificators(const char **str)
{
	int		spec;

	spec = 0;
	**str == 'd' || **str == 'i' ? spec = 'd' : 0;
	**str == 'u' ? spec = 'u' : 0;
	**str == 'o' ? spec = 'o' : 0;
	**str == 'b' ? spec = 'b' : 0;
	**str == 'B' ? spec = 'B' : 0;
	**str == 's' ? spec = 's' : 0;
	**str == 'x' ? spec = 'x' : 0;
	**str == 'X' ? spec = 'X' : 0;
	**str == 'c' ? spec = 'c' : 0;
	**str == 'p' ? spec = 'p' : 0;
	**str == '%' ? spec = '%' : 0;
	**str == 'f' ? spec = 'f' : 0;
	**str == 'F' ? spec = 'F' : 0;
	return (spec);
}
