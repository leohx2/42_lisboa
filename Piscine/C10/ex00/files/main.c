#include "stock_ft.h"

int main(int argc, char **argv)
{
    if (!(ft_check_arg(argc)))
        return (0);
    ft_display_file(argv[1]);
    return (0);
}