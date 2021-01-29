#ifndef FT_BOOLEAN
#define FT_BOOLEAN
#include <unistd.h>

typedef enum
{
    false = 0,
    true = 1

}   t_bool;

#define TRUE true
#define FALSE false

#define EVEN(number) (number % 2 == 0)

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

#define SUCCESS 0

#endif // ending FT_boolean