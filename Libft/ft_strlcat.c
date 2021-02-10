
unsigned int    ft_len(const char *str)
{
    unsigned int index;

    index = 0;
    while (str[index])
        index++;
    return (index);
}

unsigned int    ft_strlcat(char *dst, const char *src, unsigned int size)
{
    unsigned int to_return;
    unsigned int index;
    unsigned int dst_size;
    unsigned int src_size;

    dst_size = ft_len(dst);
    src_size = ft_len(src);
    index = dst_size;
    if (dst_size >= size)
        return (size + src_size);
    else
        to_return = dst_size + src_size;
    while(index < size - 1)
    {
        dst[index] = src[index - dst_size];
        index++;
    }
    dst[index] = '\0';
    return (to_return);
}
