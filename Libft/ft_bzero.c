
void    ft_bzero(void *s, unsigned int n)
{
    unsigned int aux;

    aux = 0;
    while(aux < n)
    {
        *(int*)s = '\0';
        s++;
        aux++;
    }
}