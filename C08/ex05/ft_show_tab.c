#include "../ex04/ft_stock_str.h"
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

void    ft_putnmbr(int number)
{
	if (number > 9)
		ft_putnmbr(number / 10);
	ft_putchar(number % 10 + 48);
}

void    ft_show_tab(struct s_stock_str *par)
{
    int index;

    index = 0;
    while (par[index].str)
    {
        ft_putstr((par + index)->str);
        ft_putstr((par + index)->copy);
        ft_putnmbr((par + index)->size);
        write(1, "\n", 1);
        index++;
    }
}