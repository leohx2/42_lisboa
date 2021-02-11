int             ft_atoi(char *str)
{
    int signal;
    int result;

    signal = 1;
    result = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n'
    || *str == '\r' || *str == '\v' || *str == '\f')
        str++;
    if (*str == 'x')
        str++;
    else if (*str == '-')
    {
        str++;
        signal = -1;
    }
    while (*str > 47 && *str < 59)
    {
        result = result * 10 + *str - 48;
        str++;
    }
    return (result * signal);
}