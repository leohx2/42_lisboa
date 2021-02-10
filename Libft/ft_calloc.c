
#include <stdlib.h>
void    *ft_calloc(unsigned int n, unsigned int size)
{
    void            *to_return;
    unsigned int    to_alloc;
    unsigned int    aux;
    int             temp[size * n];

    temp[0] = 0;
    aux = 0;
    to_alloc = size * n;
    if (n == 0 || size == 0)
        return (0);
    if(!(to_return = malloc(to_alloc)))
        return (0);
    while (aux < to_alloc)
    {
        temp[aux] = 0;
        aux++;
    }
    to_return = temp;
    return (to_return);
}