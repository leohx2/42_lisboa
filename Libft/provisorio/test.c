
#include <stdio.h>
#include <stdlib.h>

char            *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char            ft_upper(unsigned int n, char c)
{
    if(c > 96 && c < 123 && n > 0)
        return (c - 32);
    else
        return (c);
}

int main()
{
    char *test;

    test = ft_strmapi("oi", ft_upper);
    printf("%s\n", test);
}