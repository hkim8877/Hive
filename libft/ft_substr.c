#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dst;
    unsigned int i;
    size_t  s_len;

    s_len = ft_strlen(s);
    if (s == NULL)
        return (NULL);
    if (start > s_len)
        len = 0;
    if (len > s_len - start)
        len = s_len - start;
    dst = malloc(sizeof(char)*(len + 1));
    if (dst == NULL)
        return (NULL);
    i = 0;
    while (len--)
    {
        dst[i] = s[start];
        i++;
        start++;
    }
    dst[i] = '\0';
    return ((char *)dst);
}
/*
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
DESCRIPTION
    Allocate (with malloc(3)) and return a new string from the string s.
    This new string starts at index 'start' and has a maximum size of 'len'.
PARAMETERS
    s: string from which to extract the new string
    start: start index of the new string in the string 's'
    len: maximum size of the new string
RETURN VALUES
    ft_substr() returns the new string; NULL if the memory allocation failed.    
*/