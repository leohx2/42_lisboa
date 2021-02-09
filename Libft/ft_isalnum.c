
int ft_isalnum(int c)
{
    if (c > 47 && c < 58)
        return (4);
    else if (c > 96 && c < 123)
        return (2);
    else if (c > 64 && c < 91)
        return (1);
    else
        return (0);
}