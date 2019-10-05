#include "printf.h"

int	parse_string(const char **str, va_list *args)
{
    int flags[5];

    flags[0] = parse_flags(str);                                    //flags
    flags[1] = parse_width(str, args);                              //width
    flags[2] = parse_precision(str, args);                          //precision
    ((flags[3] = parse_modificators(str)) != 0) ? (*str)++ : 0;     //modificators
    ((flags[4] = parse_specificators(str)) != 0) ? (*str)++ : 0;    //specificator

    if (flags[4] == 'd')
        return (spec_signed(args, flags));
    else if (strchr("uoxX", flags[4]))
        return (spec_unsigned(args, flags));
    else if (strchr("fFeEgGaA", flags[4]))
        return (spec_float(args, flags));
    else if (flags[4] == 'c')
        return (spec_char(args, flags));
    else if (flags[4] == 's')
        return (spec_string(args, flags));
    else if (flags[4] == 'p')
        return (spec_pointer(args, flags));
    else if (flags[4] == '%')
        return (spec_per(args, flags));
    return (0);
}