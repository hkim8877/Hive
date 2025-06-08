#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char *ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char *ft_strjoin(const char *s1, const char *s2)
{
	char *dest;
	char *result;
	size_t s1_len;
	size_t s2_len;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(s1_len + s2_len + 1);
	if (!dest)
		return (NULL);
	result = dest;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (result);	
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	char *dest;
	unsigned int i;
	size_t s_len;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}