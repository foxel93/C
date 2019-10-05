#include "libft.h"

int ft_putnstr(char *str, size_t n)
{
    write(1, str, n);
    return (0);
}