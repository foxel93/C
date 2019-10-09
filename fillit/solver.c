/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:52:26 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/13 21:58:50 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			overlap(t_tet *tet)
{
	char			i;
	char			j;

	i = -1;
	while ((tet[++i]).l)
	{
		j = i;
		while (j >= 1 && (j--))
			if (!(tet[j].fig ^ tet[i].fig))
			{
				tet[i].prev = &(tet[j]);
				break ;
			}
	}
}

static int			solver(t_tet *tet, char size, short *map)
{
	if (!(tet->l))
		return (1);
	if (!tet->prev && !(tet->y = 0))
		tet->x = 0;
	else if ((tet->y = tet->prev->y))
		tet->x = tet->prev->x + tet->w - 1;
	while (tet->y <= size - tet->h)
	{
		while (tet->x <= size - tet->w)
		{
			if (!(*(t_ulong *)(map + tet->y) & tet->fig << tet->x))
			{
				*(t_ulong *)(map + tet->y) ^= tet->fig << tet->x;
				if (solver(tet + 1, size, map))
					return (1);
				*(t_ulong *)(map + tet->y) ^= tet->fig << tet->x;
			}
			(tet->x)++;
		}
		tet->x = 0;
		(tet->y)++;
	}
	return (0);
}

static int			repeat(t_tet *tet, t_tet *cur, char l)
{
	while (l-- >= 'A')
	{
		cur->x = tet->x;
		cur->y = tet->y;
		cur->w = tet->w;
		cur->h = tet->h;
		cur->l = tet->l;
		tet->x = 0;
		tet->y = 0;
		cur++;
		tet++;
	}
	return (0);
}

unsigned char		search_size(t_tet *tet, char const l)
{
	unsigned char	size;
	short			*map;
	t_tet			*cur;

	size = 13;
	if (!(cur = (t_tet *)malloc(sizeof(t_tet) * (l - 'A' + 1))))
		return (0);
	if (!(map = ft_memalloc(sizeof(short) * 16)))
		return (0);
	overlap(tet);
	while (size * size >= ((l + 1 - 'A') * 4) && solver(tet, size, map))
	{
		size--;
		ft_bzero(map, sizeof(short) * 16);
		repeat(tet, cur, l);
	}
	repeat(cur, tet, l);
	ft_memdel((void **)&map);
	ft_memdel((void **)&cur);
	return (size + 1);
}
