#include "printf.h"

int	ft_putnstr(char *str, int max)
{
	int	i;

	i = -1;
	while (+i < max && str[i] != '\0')
		ft_putchar(str[i]);
	return (i);
}
