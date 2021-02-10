
int     ft_confirm(const char *dest, const char *src, unsigned int aux)
{
    int aux2;

    aux2 = 0;
    while(src[aux2])
    {
        if (src[aux2] != dest[aux])
            return (0);
        aux++;
        aux2++;
    }
    return (1);
}

char    *ft_strnstr(const char *dest, const char *src, unsigned int len)
{
    unsigned int    aux;
    int             to_return;

    aux = 0;
    to_return = 0;
    while(dest[aux] && aux < len)
    {
        if (dest[aux] == src[0])
        {
            to_return = ft_confirm(dest, src, aux);
            if (to_return == 1)
                return ((char*)(dest + aux));
        }
        aux++;
    }
    return (0);
}