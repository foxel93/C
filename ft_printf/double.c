#include "printf.h"


int 	print_ldouble(va_list *args, int flags[5])
{
    int len;
    long double output;
    int width;

    flags[2] == -2 ? flags[2] = 6 : 0;
    flags[2] == -1 ? flags[2] = 0 : 0;
    output = (long double)va_arg(*args, long double);
    len = ft_double_length(output, flags);

    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;

    //ft_align_int(output, flags, width, len);
    return (1);
}

char *ft_double_to_int(double num, const int flags[5], int size)
{
    int len;
    long long left;
    char c;
    char *a;
    size_t i;

    if (!(a = ft_strnew(size + flags[2])))
        return (NULL);
    len = flags[2];
    i = 0;
    left = (int)num;
    while (--size >= 0 && ++i)
    {
        c = (char)(left % 10);
        a[size] = (char)((c > 0 ? c : -c) + '0');
        left /= 10;
    }
    len > 0 ? a[i++] = '.' : 0;
    while (len-- > 0)
    {
        num = num * 10;
        c = (char)((long long)num % 10LL);
        a[i++] = (char)((c > 0 ? c : -c) + '0');
    }
    a[i] = '\0';
    return (a);
}

int 	print_double(va_list *args, int flags[5])
{
    int len;
    double output;
    int width;
    int count;
    char *str;

    output = (double)va_arg(*args, double);
    if (!ft_isnan(output, flags) || !ft_isplus_inf(output, flags) || !ft_isminus_inf(output, flags))
        return (1);
    count = ft_count((int)output);
    flags[2] == -2 ? flags[2] = 6 : 0;
    flags[2] == -1 ? flags[2] = 0 : 0;
    if(!(str = ft_double_to_int(output, flags, count)))
        return (0);
    flags[2] > 0 ? flags[2]++ : 0;
    len = ft_double_length(output, flags);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_double(output, flags, width - len, str);
    return (1);
}