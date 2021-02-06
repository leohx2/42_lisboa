
#include <stdio.h>
#include "ft_strs_to_tab.c"
#include "ft_stock_str.h"
#include "../ex05/ft_show_tab.c"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int main(int argc, char **argv)
{
	argc -= 1;
	argv++;
	t_stock_str *t = ft_strs_to_tab(argc, argv);
	ft_show_tab(t);
	return 0;
}