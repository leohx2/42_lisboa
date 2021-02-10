
void    *ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
    unsigned int aux;

    aux = 0;
    while (*(char*)src != '\0' && aux < n)
    {
        *(char*)dest = *(char*)src;
        dest++;
        src++;
        if(*(char*)(dest - 1) == c)
            return (dest);
        aux++;
    }
    *(char*)dest = 0;
    return (0);
}