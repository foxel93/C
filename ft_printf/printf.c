#include "printf.h"

int ft_printf(const char *format, ...)
{
    va_list	args;

    va_start(args, format);
    while (*format != '\0')
    {
        if (*format == '%') {
            if (!parse_string(&format, &args))
                return (0);
        }
        else
            ft_putchar(*format++);
        ;
    }
    va_end(args);
    return (0);
}
