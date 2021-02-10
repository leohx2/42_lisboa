
#include <stdlib.h>

int     ft_strlen(const char *str)
{
    int     cont;

    cont = 0;
    while(str[cont])
        cont++;
    return (cont);
}
char    *ft_strdup(const char *s)
{
    int     aux;
    char    *to_return;

    aux = 0;
    if(!(to_return = (char*)malloc(ft_strlen(s) * sizeof(char))))
        return (0);
    while (s[aux])
    {
        to_return[aux] = s[aux];
        aux++;
    }
    to_return[aux] = '\0';
    return (to_return);
}