#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
    size_t  i;

    d = (unsigned char *)dest;
    s = (const unsigned char *) src;
    i = 0;
    if (dest == NULL || src == NULL || n == 0)
        return (dest);
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

#include <string.h>
#include <stdio.h>
int main()
{
    char src[14] = "adbcd";
    char dest[20] = "hel";

    ft_memcpy(dest, src, 14);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}