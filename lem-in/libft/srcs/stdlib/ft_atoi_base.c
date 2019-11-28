#include "libft.h"

static int	verify_base_nbr(char c, int base)
{
	if (base <= 10)
		return (ft_isdigit(c));
	return (ft_isdigit(c) || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int			ft_atoi_base(const char *str, int base)
{
	int		i;
	int		nbr;
	int		sign;

	if (!str || (base < 2 || base > 16))
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		str[i++] == '-' ? sign = -1 : sign;
	while (str[i] && verify_base_nbr(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}