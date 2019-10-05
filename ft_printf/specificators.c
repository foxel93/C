#include "printf.h"

int    spec_signed(va_list *args, const int flags[5])
{
    if (flags[3] == (int)('h') + (int)('h'))
        printf("hhd - signed char");
    else if (flags[3] == (int)('l') + (int)('l'))
        printf("lld - long long int");
    else if (flags[3] == 'h')
        printf("hd - short int");
    else if (flags[3] == 'l')
        printf("ld - long int");
    else if (flags[3] == 'j')
        printf("jd- intmax_t");
    else if (flags[3] == 'z')
        printf("zd - size_t");
    else if (flags[3] == 't')
        printf("td - ptrdiff_t");
    else
        printf("d - int");
    return (1);
}

int    spec_unsigned(va_list *args, const int flags[5])
{
    if (flags[3] == (int)('h') + (int)('h'))
        printf("hhd - unsigned char");
    else if (flags[3] == (int)('l') + (int)('l'))
        printf("lld - unsigned long long int");
    else if (flags[3] == 'h')
        printf("hd - unsigned short int");
    else if (flags[3] == 'l')
        printf("ld - unsigned long int");
    else if (flags[3] == 'j')
        printf("jd- intmax_t");
    else if (flags[3] == 'z')
        printf("zd - size_t");
    else if (flags[3] == 't')
        printf("td - ptrdiff_t");
    else
        printf("d - unsigned int");
    return (1);
}

int    spec_float(va_list *args, const int flags[5])
{

    if (flags[3] == 'L')
    {

    }
    return (1);
}