#include <ctype.h>
#include "libft.h"
#include <stdio.h>
int main()
{
    printf("%c\n",tolower('A'));
    printf("%c FT\n",ft_tolower('A'));
    printf("%c\n",tolower('a'));
    printf("%c FT\n",ft_tolower('a'));
    printf("%c\n",tolower('z'));
    printf("%c FT\n",ft_tolower('z'));
    printf("%c\n",tolower('Z'));
    printf("%c FT\n",ft_tolower('Z'));
    return 0;
    
}