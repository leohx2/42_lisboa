#ifndef TEST_H
#define TEST_H
#include <unistd.h>

void    ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
}

int ft_check_arg(int argc)
{
    if (argc < 2)
    {
        ft_putstr("File name missing.\n");
        return (0);
    }
    else if (argc > 2)
    {
        ft_putstr("Too many arguments.\n");
        return (0);
    }
    return (1);
}

#endif