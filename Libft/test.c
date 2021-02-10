#include <string.h>
#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main()
{
    char test1[50] = "Hello World";
    char *test2 = strdup(test1);
    char *test3 = ft_strdup(test1);

    printf("%s // original\n", test2);
    printf("%s // funcao_l\n", test3);
}