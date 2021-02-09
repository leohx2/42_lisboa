#include <stdlib.h>

int *ft_range(int min, int max)
{
  int *array_return = (int*)malloc((max - min) * sizeof(int));
  int count;

  count = 0;
  if (min >= max)
  {
    free(array_return);
    return (NULL);
  }
  while (min < max)
  {
    array_return[count] = min;
    count++;
    min++;
  }
  return(array_return);
}
