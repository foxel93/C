/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:59:17 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/13 21:59:18 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"
# include <stdio.h>

typedef unsigned long long t_ulong;

typedef struct		s_tet
{
	char			l;
	t_ulong			fig;
	unsigned char	w;
	unsigned char	h;
	unsigned char	x;
	unsigned char	y;
	struct s_tet	*prev;
}					t_tet;

unsigned char		search_size(t_tet *tet, char l);
char				read_file(int fd, t_tet *tet);
#endif
