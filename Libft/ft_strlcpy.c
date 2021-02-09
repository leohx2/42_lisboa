
unsigned int ft_strlcpy(char *dst, const char *src, unsigned int size)
{
    unsigned int index;
    unsigned int count;

    count = 0;
    index = 0;
    while (src[index])
    {
        index++;
    }
    if (size == 0)
        return (index);
    while (count < (size - 1) && src[count])
    {
        dst[count] = src[count];
        count++;
    }
    dst[count] = '\0';
    return (index);
}