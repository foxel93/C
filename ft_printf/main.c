/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:00:21 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 15:08:15 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	int c;

	c = INT_MIN;
	char *dec = "ser";
	char *pec = dec;
	//ft_printf("%-10.9f help\n",0.0/0.0);
    printf("bleat %#9.12p new\n",pec);
    //printf("%-+15.5hhd\n",100);
	return (0);
}
