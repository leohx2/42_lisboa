
void    *ft_memcpy(void *dest, const void *src, unsigned int n)
{
    unsigned int compare;

    compare = 0;
    while(compare < n && src != '\0')
    {
        *(char*)dest = *(char*)src;
        dest++;
        src++;
        compare++;
    }
    *(char*)dest = 0;
    return (dest);
}