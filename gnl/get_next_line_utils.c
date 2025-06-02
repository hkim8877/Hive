int ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == t)
		return ((char *)str);
	return (NULL);
}
char *ft_strdup(const char *src)
{

}

char *ft_strjoin(const char *str1, const char *str2)