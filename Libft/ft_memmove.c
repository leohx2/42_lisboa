
void    *ft_memmove(void *dest, const void *src, unsigned int n)
{
    char c;

    while (n--)
    {
        c = *(char*)src;
        *(char*)dest = c;
        src++;
        dest++;
    }
    return (dest);
}