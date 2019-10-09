/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:52:38 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/13 21:56:06 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			*ft_strnew_c(size_t size, char c)
{
	char			*str;
	char			*tmp;

	if (!(str = ft_strnew(size)))
		return (NULL);
	else
	{
		tmp = str;
		while (str - tmp < size)
			*str++ = c;
		return (tmp);
	}
}

static void			print_map(t_tet *tet, char l, char size)
{
	char			*map;
	unsigned		y;
	unsigned		x;

	map = ft_strnew_c(size * (size + 1), '.');
	while (l-- >= 'A' && (y = -1))
	{
		while (++y < tet->h && (x = -1))
			while (++x < tet->w)
				if ((tet->fig >> (16 * y + x)) & 1LL)
					map[(tet->y + y) * (size + 1) + (tet->x + x)] = tet->l;
		tet++;
	}
	y = -1;
	while (++y < size)
		map[y * (size + 1) + size] = '\n';
	ft_putstr_fd(map, 1);
	ft_strdel(&map);
}

void				ft_exit(int error, char *str)
{
	if (error == 1)
	{
		ft_putstr_fd("usage: ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" [input file]\n", 1);
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		ft_putstr_fd("error\n", 1);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int					main(int argc, char **argv)
{
	int				fd;
	char			l;
	t_tet			*tet;
	unsigned char	size;

	if (argc != 2)
		ft_exit(1, argv[0]);
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_exit(2, NULL);
		if (!(tet = ft_memalloc(sizeof(t_tet) * 27)))
			ft_exit(2, NULL);
		if (!(l = read_file(fd, tet)))
			ft_exit(2, NULL);
		if (!(size = search_size(tet, l)))
			ft_exit(2, NULL);
		print_map(tet, l, size);
		ft_memdel((void **)&tet);
		if (close(fd) == -1)
			ft_exit(2, NULL);
		ft_exit(0, NULL);
	}
	return (0);
}
