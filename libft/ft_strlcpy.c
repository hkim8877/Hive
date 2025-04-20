#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  s;
    size_t  i;

    s = 0;
    i = 0;
    while (src[s] != '\0')
        s++;  
    if (size == 0)
        return (s);
    while (src[i] != '\0' && i < (size - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (s);
}

#include <stdio.h>
#include <bsd/string.h> 

int main()
{
    char dest[10] = "a";
    const char *src = "hello";

    size_t re = ft_strlcpy(dest, src, 0);

    printf("%zu\n", re);
    printf("%s\n", dest);

    return 0;
}
