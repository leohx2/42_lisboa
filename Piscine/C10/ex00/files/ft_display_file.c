// oi
#include <fcntl.h>
void    ft_putstr(char *str);
void    ft_display_file(char *argv)
{
    int file;
    char void_c;

    file = open(argv, O_RDONLY);
    if(file == -1)
    {
        ft_putstr("Cannot read file.\n");
        return;
    }
    while(read(file, &void_c, sizeof(void_c)) > 0)
    {
        write(1, &void_c, sizeof(void_c));
    }
    close(file);
}