#include "ft_display_file.c"
#include "errors.c"

int main(int argc, char **argv)
{
    if (!(ft_check_arg(argc)))
        return (0);
    ft_display_file(argv[1]);
    return (0);
}