#include "ft_stock_str.h"
#include <stdlib.h>

int     ft_str_len(char *str)
{
    int count;

    count = 0;
    while(str[count])
    {
        count++;
    }
    return (count);
}

char				*ft_strdup(char *src)
{
	char	*dupli;
	int		i;

	i = 0;
	if (!(dupli = malloc(ft_str_len(src))))
		return (dupli);
	while (src[i])
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = 0;
	return (dupli);
}

struct  s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    struct s_stock_str  *to_return;
    int count;

	if (!(to_return = malloc(sizeof(struct s_stock_str) * (ac + 2))))
		return (0);
    count = 0;
    while(count < ac)
    {
        to_return[count].size = ft_str_len(av[count]);
        to_return[count].str = av[count];
        to_return[count].copy = ft_strdup(av[count]);
        count++;
    }
    to_return[count].str = NULL;
    return (to_return);
}