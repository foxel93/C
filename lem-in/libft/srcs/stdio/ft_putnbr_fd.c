#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	tmp;

	if (nb < 0)
	{
		tmp = (unsigned int)-nb;
		ft_putchar_fd('-', fd);
	}
	else
		tmp = (unsigned int)nb;
	if (tmp >= 10)
		ft_putnbr_fd((int)(tmp / 10), fd);
	ft_putchar_fd((char)(tmp % 10 + '0'), fd);
}
