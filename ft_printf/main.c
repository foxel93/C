#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

//FLAG
#define F_HASH  0x80
#define F_ZERO  0x40
#define F_MINUS 0x20
#define F_SPACE 0x10
#define F_PLUS  0x08
#define F_APOS  0x04
#define F_ARAB  0x02

#define TYPE_STR    " diouxXeEfFgGaAcspn%"

typedef struct      s_str
{
    char            *str;
    char            flag;    //#0- +'|
    int             width;
    int             accuracy;
    char            mod_length; //hh,h,l,ll,L,q,j,z,t
    char            type;       //d,i,o,u,x,X,e,E,f,F,g,G,a,A,c,s,p,n,%
    struct s_str    *next;
    struct s_str    *prev;
}                   t_str;

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

int ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
    return (0);
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_error(void)
{
    ft_putnstr("ERROR\n", 6);
    return (0);
}

int     ft_flag_str(const char **str)
{
    int flag;

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

int     ft_accuracy_str(const char **str, va_list *arg)
{
    if (**str == '.')
    {
        (*str)++;
        return (ft_width_str(str, arg));
    }
    return (-1);
}

int     ft_modification_str(const char **str)
{
    if (**str == 'h' && *((*str) + 1) == 'h')
    {
        (*str) += 2;
        return (1);
    }
    if (**str == 'l' && *((*str) + 1) == 'l')
    {
        (*str) += 2;
        return (4);
    }
    if (**str == 'h' && (*str)++)
        return (2);
    if (**str == 'l' && (*str)++)
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

int     ft_type_str(const char **str, va_list *arg)
{
    int i;

    i = 1;
    while (i < 20)
    {
        if (**str == TYPE_STR[i])
        {
            (*str)++;
            return (i);
        }
        i++;
    }
    return (-1);
}

t_str   *ft_newlst_str(char *str)
{
    t_str *list;

    if (!(list = (t_str *)malloc(sizeof(t_str))))
        return (NULL);
    list->flag = -1;
    list->accuracy = -1;
    list->width = -1;
    list->type = -1;
    list->mod_length = -1;
    list->next = NULL;
    list->prev = NULL;

    return (list);
}

void    ft_addlst_str(t_str **current, t_str **list)
{
    if (*current == NULL)
        *current = *list;
    else {
        (*list)->prev = *current;
        (*current)->next = *list;
    }
}

char    *ft_newstr_str(const char **format, va_list *args)
{
    int mas[5];

    mas[0] = ft_flag_str(format);
    mas[1] = ft_width_str(format, args);
    mas[2] = ft_accuracy_str(format, args);
    mas[3] = ft_modification_str(format);
    mas[4] = ft_type_str(format, args);
    //if (mas[4] == 0)
    //    return (NULL);
    if (!mas[0] && (mas[1] + mas[2]) == -2 && !mas[3] && mas[4] == 19)      //0 -1 -1 0 #
       ft_putstr("%");
    return (NULL);
}

int ft_printf(const char *format, ...)
{
    va_list	args;
    int		ret;
    char    *str;
    char    *tmp;

    t_str *head;

    head = NULL;
    va_start(args, format);
    while (*format != '\0')
    {
        str = (char *)format;
        while (*format != '\0' && *format != '%')
            format++;


        ft_newstr_str(&format, &args);
        printf ("\t %s",format);
        str = (char *)format;
        printf ("\n");
    }
    va_end(args);
    return (0);
}

int main() {
    ft_printf("%# 123dd",2,1,3,4);
    return 0;
}