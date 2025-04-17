#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *temp;
    size_t i;

    temp = (unsigned char*) s;
    i = 0;
    while (i < n)
    {
        temp[i] = (unsigned char)c;
        i++;
    }
    return (s);

}

#include <stdio.h>
int main()
{
    char test[] = 'abcdef';
    printf("%s\n", ft_memset(test,'-', 3));
}