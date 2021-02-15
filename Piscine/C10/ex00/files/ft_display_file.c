#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void    ft_display_file(char *argv)
{
    int file;
    char void_c;

    file = open(argv, O_RDONLY);
    if(file == -1)
    {
        printf("Cannot read file.\n");
        return;
    }
    while(read(file, &void_c, sizeof(void_c)) > 0)
    {
        write(1, &void_c, sizeof(void_c));
    }
    close(file);
}