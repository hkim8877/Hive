#include "pipex.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while(s[i] != '\0')
       i++;
    return (i);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    return (0);
    
}

char    *ft_strdup(const char *s)
{
       int    len;
       int    i;
       char   *dest;

       len = 0;
       while (s[len] != '\0')
              len++;
       dest = (char *)malloc(sizeof(char) * (len + 1));
       if (!dest)
              return (NULL);
       i = 0;
       while (i < len)
       {
              dest[i] = s[i];
              i++;
       }
       dest[i] = '\0';
       return (dest);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
    size_t  i;

    if (dest == NULL || src == NULL || n == 0)
        return (dest);
    d = (unsigned char *)dest;
    s = (const unsigned char *) src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  d_len;
    size_t  s_len;
    size_t  i;

    d_len = 0;
    s_len = 0;
    i = 0;
    while (dst[d_len] != '\0' && (d_len < size))
        d_len++;
    while (src[s_len] != '\0')
        s_len++;
    if (size <= d_len)
        return (size + s_len);
    while (src[i] != '\0' && (d_len + i) < (size - 1))
    {
        dst[d_len + i] = src[i];
        i++;
    }
    dst[d_len + i] = '\0';
    return (d_len + s_len);
}