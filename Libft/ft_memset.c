
void    *ft_memset(void *s, int c, unsigned int n)
{
    unsigned int    aux;

    aux = 0;
    while(aux < n)
    {
        *(int*)s = c;
        s++;
        aux++;
    }
    return (s);
}