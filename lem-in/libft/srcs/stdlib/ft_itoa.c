#include "libft.h"

static void	append(char c, char *s, int *len)
{
	if (s != NULL)
		s[*len] = c;
	(*len)++;
}

static void	putnbr(int nb, char *s, int *len)
{
	unsigned int	tmp;

	if (nb < 0)
	{
		tmp = (unsigned int)-nb;
		append('-', s, len);
	}
	else
		tmp = (unsigned int)nb;
	if (tmp >= 10)
		putnbr((int)(tmp / 10), s, len);
	append(tmp % 10 + '0', s, len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = 0;
	putnbr(n, NULL, &len);
	str = ft_strnew(len);
	len = 0;
	putnbr(n, str, &len);
	return (str);
}
