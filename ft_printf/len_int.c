#include "printf.h"

int ft_int_length(ssize_t num, const int flags[5])
{
	size_t len;

	len = 0;
	if (num < 0 || (flags[0] & F_P) == F_P || (flags[0] & F_S) == F_S)
		len = 1;
	if (num == 0)
	    len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int ft_uint_length(size_t num, const int flags[5], int base)
{
    size_t len;

    len = 0;
    base == 32 ? base = 16 : 0;
    if (num == 0)
        len = 1;
    while (num != 0)
    {
        num /= base;
        len++;
    }
    return (len);
}

int ft_uint_perc_len(size_t num, const int flags[5], int base)
{
    int len;
    int s;

    s = 0;
    len = 0;
    base == 32 ? base = 16 : 0;
    if (((flags[0] & F_H) == F_H) && base == 8)
        s = 1;
    if (((flags[0] & F_H) == F_H) && base == 16)
        s = 2;
    if (num == 0)
        len = 1;
    while (num != 0)
    {
        num /= base;
        len++;
    }
    if (flags[2] > len)
        len = flags[2];
    return (len + s);
}

int ft_int_perc_len(ssize_t num, const int flags[5])
{
    int len;
    int s;

    len = 0;
    s = 0;
    if (num < 0 || (flags[0] & F_P) == F_P || (flags[0] & F_S) == F_S)
        s = 1;
    if (num == 0)
        len = 1;
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    if (flags[2] > len)
        len = flags[2];
    return (len + s);
}