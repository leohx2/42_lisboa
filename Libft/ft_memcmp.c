
int ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
    int s1_value;
    int s2_value;

    s1_value = *(char*)s1;
    s2_value = *(char*)s2;
    if (n == 0)
        return (0);
    while (n-- && *(char*)s1 == *(char*)s2)
    {
        s1_value += *(char*)s1;
        s2_value += *(char*)s2;
        s1++;
        s2++;
    }
    if (n > 0 && *(char*)s1 && *(char*)s2)
    {
        s1_value += *(char*)s1;
        s2_value += *(char*)s2;
    }    
    return (s1_value - s2_value);
}