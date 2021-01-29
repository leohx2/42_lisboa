#include <stdlib.h>

int   ft_strlen(char *src)
{
    int count;

    count = 0;
    while(src[count] != '\0')
    {
      count++;
    }
    return (count);
}

char  *ft_strdup(char *src)
{
  char *dest = (char*) malloc((ft_strlen(src) + 1) * sizeof(char));
  int count;

  if (dest == NULL)
    return (dest);
  count = 0;
  while(src[count] != '\0')
  {
    dest[count] = src[count];
    count++;
  }
  dest[count] = '\0';
  return (dest);
}
