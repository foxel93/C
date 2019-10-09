/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:42:11 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/02 15:58:52 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int			ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (0);
}

int			main(int argc, char **argv)
{
	char	*file_name;
	int		fd;
	int		r;
	char	c;

	if (argc == 1)
		return (ft_putstr("File name missing.\n"));
	if (argc > 2)
		return (ft_putstr("Too many arguments.\n"));
	file_name = argv[1];
	if (!(fd = open(file_name, O_RDONLY)))
		return (0);
	while ((r = read(fd, &c, 1)) && r != -1)
		ft_putchar(c);
	close(fd);
	return (0);
}
