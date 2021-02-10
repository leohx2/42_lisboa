#include <string.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char test1[50] = "123456";
    char test2[50] = "123456";
    memset(test1, '0', 6);
    ft_memset(test2, '0', 6);
    printf("%s ORG\n",test1);
    printf("%s FCT\n", test2);

    return(0);
}