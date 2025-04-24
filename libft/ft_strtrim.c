#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *dst;
    size_t  s1_len;
    int i;

    if (s1 == 0 || set == 0)
        return (NULL);
    s1_len = ft_strlen(s1);
    dst = (char *)malloc(s1_len + 1);
    if (dst == 0)
        return (NULL);
    ft_memcpy(dst, s1, s1_len);
    i = 0;
    if (dst[i] == set[i])
        while (*set != '0')
        {

        }
    


}