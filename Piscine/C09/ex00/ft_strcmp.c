int ft_strcmp(char *s1, char *s2)
{
    int s1_value;
    int s2_value;

    s1_value = *s1;
    s2_value = *s2;
    while(*s1 == *s2 && *s1)
    {
        s1_value += *s1;
        s2_value += *s2;
        s1++;
        s2++;
        if (!*s1 && *s2 )
            s2_value += 1;
        if (!*s2 && *s1 )
            s1_value += 1;
    }

    if (*s2 && *s1)
    {
        s1_value += *s1;
        s2_value += *s2;
    }
    return(s1_value - s2_value);
}