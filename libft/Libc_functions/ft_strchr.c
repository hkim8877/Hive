#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    char t;
    
    t = (char)c;
    while (*s != '\0')
    {
        if (*s == t)
            return ((char *)s);
        s++;
    }
    if (t == '\0')
        return ((char *)s);
    return (NULL);
}

#include <stdio.h>
#include <string.h>
int main()
{
    char test[]= "Hello";
    int c = '\0';

    printf("%s\n", ft_strchr(test, c));
     printf("%s\n", strchr(test,c));
    // printf("%s\n", test);
}