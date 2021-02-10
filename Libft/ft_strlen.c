
unsigned int    ft_strlen(const char *s)
{
    unsigned int size;

    size = 0;
    while (*s)
    {
        size++;
        s++;
    }
    return (size);
}