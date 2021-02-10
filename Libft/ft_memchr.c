
void    *ft_memchr(const void *s, int c, unsigned int n)
{
    unsigned char aux;

    aux = c;
    while (n--)
    {
        if(*(unsigned char*)s == aux)
            return ((unsigned char*)s);
        s++;
    }
    return (0);
}