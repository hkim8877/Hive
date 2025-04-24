#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dst;
    size_t d_len;
    unsigned int i;

    if (s == 0)
        return (NULL);
    if (start > ft_strlen(s))
        d_len = 0;
    if (len > ft_strlen(s))
        d_len = ft_strlen(s);
    else
        d_len = len;
    dst = malloc(sizeof(char)*(d_len + 1));
    if (dst == 0)
        return (NULL);
    i = 0;
    while (d_len--)
    {
        dst[i] = s[start];
        i++;
        start++;
    }
    dst[i] = '\0';
    return ((char *)dst);
}
#include <stdio.h>
int main()
{
    char a[] = "123456789";
    char b[] = "";
    
    printf("1. normal: %s\n", ft_substr(a,3,5));
    printf("2. start > s_len: %s\n", ft_substr(a, 15,3));
    printf("3. len > s_len: %s\n", ft_substr(a, 3, 15));
    printf("4. s = empty: %s\n", ft_substr(b,3,5));
}