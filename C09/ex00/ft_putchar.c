#include <unistd.h>

void    ft_putchat(char c)
{
    write(1, &c, 1);
}