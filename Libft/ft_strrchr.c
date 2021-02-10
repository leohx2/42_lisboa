
char    *ft_strrchr(const char *s, int c)
{
    int aux;
    int to_return;

    aux = 0;
    to_return = 0;
    while (s[aux])
    {
        if (s[aux] == c)
            to_return = aux;
        aux++;
    }
    if (to_return > 0)
        return ((char*)(s + to_return));
    else
        return (0);
}
