#include "printf.h"

int     parse_width(const char **str, va_list *arg)
{
    long a;

    a = 0;
    if (**str == '*') {
        (*str)++;
        return (va_arg(*arg, int));
    }
    if (!ft_isdigit(**str))
        return (-1);
    while (ft_isdigit(**str) && a < INT_MAX)
    {
        a = a * 10 + (**str - '0');
        (*str)++;
    }
    if (a > INT_MAX)
        return (0);
    return ((int)a);
}

int     parse_precision(const char **str, va_list *arg)
{
    if (**str == '.')
    {
        (*str)++;
        return (parse_width(str, arg));
    }
    return (-2);
}

int     parse_modificators(const char **str)
{
    if (**str == 'h' && *((*str) + 1) == 'h')
    {
        (*str)++;
        return ((int)'h' + (int)'h');
    }
    if (**str == 'l' && *((*str) + 1) == 'l')
    {
        (*str)++;
        return ((int)'l' + (int)'l');
    }
    if (**str == 'h')
        return ('h');
    if (**str == 'l')
        return ('l');
    if (**str == 'L')
        return ('L');
    if (**str == 'q')
        return ('q');
    if (**str == 'j')
        return ('j');
    if (**str == 'z')
        return ('z');
    if (**str == 't')
        return ('t');
    return (0);
}

int     parse_flags(const char **str)
{
    int flag;
    int tmp;

    flag = 0;
    while (*(++(*str)))
    {
        tmp = flag;
        **str == '#' ? flag |= F_HASH : 0;
        **str == '0' ? flag |= F_ZERO : 0;
        **str == '-' ? flag |= F_MINUS : 0;
        **str == ' ' ? flag |= F_SPACE : 0;
        **str == '+' ? flag |= F_PLUS : 0;
        if (tmp == flag)
            break ;
    }
    if ((flag | F_MINUS) == F_MINUS && (flag | F_ZERO) == F_ZERO)
        flag -= F_ZERO;
    if ((flag | F_PLUS) == F_PLUS && (flag | F_SPACE) == F_SPACE)
        flag -= F_SPACE;
    return (flag);
}

int     parse_specificators(const char **str)
{
    int spec;

    spec = 0;
    **str == 'd' || **str == 'i' ? spec = 'd' : 0;
    **str == 'u' ? spec = 'u' : 0;
    **str == 'o' ? spec = 'o' : 0;
    **str == 's' ? spec = 's' : 0;
    **str == 'x' ? spec = 'x' : 0;
    **str == 'X' ? spec = 'X' : 0;
    **str == 'c' ? spec = 'c' : 0;
    **str == 'p' ? spec = 'p' : 0;
    **str == '%' ? spec = '%' : 0;
    **str == 'f' || **str == 'F' ? spec = 'f' : 0;
    **str == 'e' ? spec = 'e' : 0;
    **str == 'E' ? spec = 'E' : 0;
    **str == 'g' ? spec = 'g' : 0;
    **str == 'G' ? spec = 'G' : 0;
    **str == 'a' ? spec = 'a' : 0;
    **str == 'A' ? spec = 'A' : 0;
    return (spec);
}