/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:52:47 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/13 21:58:25 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_count_x(char const *buff)
{
	unsigned char	i;
	unsigned char	block;

	i = -1;
	block = 0;
	while (++i < 20)
		if (buff[i] == '#')
		{
			if (i >= 1 && buff[i - 1] == '#')
				block++;
			if (i <= 20 && buff[i + 1] == '#')
				block++;
			if (i >= 5 && buff[i - 5] == '#')
				block++;
			if (i <= 14 && buff[i + 5] == '#')
				block++;
		}
	return (block == 6 || block == 8);
}

static int			validator(char const *buff, char const count)
{
	unsigned char	i;
	unsigned char	count_x;

	count_x = 0;
	i = -1;
	while (++i < 20)
		if (i % 5 != 4)
		{
			if (buff[i] == '#')
				count_x++;
			else if (buff[i] != '.')
				return (0);
		}
		else if (buff[i] != '\n')
			return (0);
	if ((count == 21 && buff[20] != '\n')
			|| count_x != 4 || !check_count_x(buff))
		return (0);
	return ((count == 21) ? 1 : 2);
}

static void			find_place(char const *buff, unsigned char *coord)
{
	unsigned char	i;

	i = -1;
	while (++i < 20)
		if (buff[i] == '#')
		{
			if (i % 5 < coord[0])
				coord[0] = i % 5;
			if (i % 5 > coord[1])
				coord[1] = i % 5;
			if (i / 5 < coord[2])
				coord[2] = i / 5;
			if (i / 5 > coord[3])
				coord[3] = i / 5;
		}
}

static t_tet		*create_fig(t_tet *tet, char *buff, char l)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	*coords;

	if (!(coords = (unsigned char *)malloc(sizeof(unsigned char) * 4)))
		return (NULL);
	coords[0] = 3;
	coords[1] = 0;
	coords[2] = 3;
	coords[3] = 0;
	find_place(buff, coords);
	tet->l = l;
	tet->w = coords[1] - coords[0] + 1;
	tet->h = coords[3] - coords[2] + 1;
	tet->fig = 0;
	y = -1;
	while (++y < tet->h && (x = -1))
		while (++x < tet->w)
			if (buff[5 * (coords[2] + y) + (coords[0] + x)] == '#')
				tet->fig |= 1LL << (16 * y + x);
	ft_memdel((void **)&coords);
	return (tet);
}

char				read_file(int const fd, t_tet *tet)
{
	char			l;
	char			count;
	char			buff[21];
	int				end;

	end = 0;
	l = 'A' - 1;
	while ((count = read(fd, buff, 21)) >= 20)
		if (++l > 'Z'
			|| !(end = validator((char const *)buff, count))
			|| !(create_fig(tet++, buff, l)))
			return (0);
	return ((char)(count || !(l >= 'A' && end == 2) ? 0 : l));
}
