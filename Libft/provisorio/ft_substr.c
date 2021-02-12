
#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start,
unsigned int len)
{
    char    *to_return;
    int     aux;

    to_return = (char*)malloc((len - start) * sizeof(char));
    aux = 0;
    while (start < len && s[start])
    {
        to_return[aux] = s[start];
        start++;
        aux++;
    }
    to_return[aux] = '\0';
    return (to_return);
}
