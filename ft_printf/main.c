#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

//FLAG
#define F_HASH  0x80
#define F_ZERO  0x40
#define F_MINUS 0x20
#define F_SPACE 0x10
#define F_PLUS  0x08
#define F_APOS  0x04
#define F_ARAB  0x02

#define TYPE_STR    " diouxXeEfFgGaAcspn"
typedef struct      s_str
{
    char *start;
    char *end;

    unsigned char   flag;    //#0- +'|
    int             width;
    int             accuracy;
    char            mod_length; //hh,h,I,II,L,q,j,z,t
    char            type;       //d,i,o,u,x,X,e,E,f,F,g,G,a,A,c,s,p,n
    struct s_str    *next;
    struct s_str    *prev;
}                   t_str;

int     ft_flag_str(const char **str)
{
    unsigned char flag;

    flag = 0;
    while (*(++(*str)))
    {
        if (**str == '#' && (flag | F_HASH) != flag)
            flag |= F_HASH;
        else if (**str == '0' && (flag | F_ZERO) != flag)
            flag |= F_ZERO;
        else if (**str == '-' && (flag | F_MINUS) != flag)
            flag |= F_MINUS;
        else if (**str == ' ' && (flag | F_SPACE) != flag)
            flag |= F_SPACE;
        else if (**str == '+' && (flag | F_PLUS) != flag)
            flag |= F_PLUS;
        else if (**str == '\'' && (flag | F_APOS) != flag)
            flag |= F_APOS;
        else if (**str == '|' && (flag | F_ARAB) != flag)
            flag |= F_ARAB;
        else
            break ;
    }
    return (flag);
}

int     ft_width_str(const char **str, va_list *arg)
{
    long a;

    a = 0;
    if (**str == '*') {
        (*str)++;
        a = va_arg(*arg, int);
        return (a);
    }
    while (isdigit(**str) && a < INT_MAX)
    {
        a = a * 10 + (**str - '0');
        (*str)++;
    }
    if (a > INT_MAX)
        return (-1);
    return ((int)a);
}

int     ft_accuracy_str(const char **str, va_list *arg)
{
    if (**str == '.')
    {
        (*str)++;
        return (ft_width_str(str, arg));
    }
    return (0);
}

int     ft_modificator_str(const char **str)
{
    if (**str == 'h' && *((*str) + 1) == 'h')
    {
        (*str) += 2;
        return (1);
    }
    if (**str == 'I' && *((*str) + 1) == 'I')
    {
        (*str) += 2;
        return (4);
    }
    if (**str == 'h' && (*str)++)
        return (2);
    if (**str == 'I' && (*str)++)
        return (3);
    if (**str == 'L' && (*str)++)
        return (5);
    if (**str == 'q' && (*str)++)
        return (6);
    if (**str == 'q' && (*str)++)
        return (7);
    if (**str == 'z' && (*str)++)
        return (8);
    if (**str == 't' && (*str)++)
        return (9);
    return (0);
}

int     ft_type_str(const char **str)
{
    int i;

    i = 1;
    while (i < 18)
    {
        if (**str == TYPE_STR[i])
        {
            (*str)++;
            return (i);
        }
        i++;
    }
    return (0);
}


/*t_str   ft_newlst_str(char *str)
{

}*/

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int ft_putnstr(char *str,size_t n)
{
    write(1, str, n);
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list	args;
    int		ret;
    char    *str;
    char    *tmp;
    int flag;
    int w;
    int a;
    int m;
    int t;

    va_start(args, format);
    str = (char *)format;
    while (*format)
    {
        while (*format != '\0' && *format != '%')
            format++;
        if (*(format + 1) == '%')
        {
            format++;
            continue ;
        }
        if ((flag = ft_flag_str(&format)) != -1)
            printf ("%d ",flag);
        if ((w = ft_width_str(&format, &args)) != -1)
            printf ("%d ",w);
        if ((a = ft_accuracy_str(&format, &args)) != -1)
            printf ("%d ",a);
        if ((m = ft_modificator_str(&format)) != -1)
            printf ("%d ",m);
        if ((t = ft_type_str(&format)) != -1)
            printf ("%d ",t);
        printf ("\t %s",format);
        printf ("\n");
        //format++;
    }
    /*if (*str)
        ft_putnstr(str, format - str);*/
    va_end(args);
    return (0);
}

int main() {
    ft_printf("%%*.*",2,1,3,4);
    return 0;
}