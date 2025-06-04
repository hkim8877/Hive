#include "get_next_line.h"

static char *read_file(int fd, char *lines)
{
	char *buffer;
	char *temp;
	ssize_t byte;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	byte = 1;
	while (byte > 0 && !ft_strchr(lines, '\n'))
	{
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}		
		buffer[byte] = '\0';
		if (!lines)
			lines = ft_strdup("");
		temp = ft_strjoin(lines, buffer);
		free(lines);
		lines = temp;
	}
	free(buffer);
	return (lines);
}
static char *extract_lines(char *lines)
{
	char *line;
	int i;

	i = 0;
	if(!lines || lines[0] == '\0')
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	line = ft_substr(lines, 0, i + 1);
	return (line);
}
static char *update_lines(char *lines)
{
	char *new_lines;
	int i;

	i = 0;
	if(!lines || lines[0] == '\0')
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	if (!lines[i])
	{
		free(lines);
		return (NULL);
	}
	new_lines = ft_strdup(&lines[i + 1]);
	free (lines);
	return (new_lines);
}
char *get_next_line(int fd)
{
	static char *lines;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = read_file(fd, lines);
	if (!lines)
		return (NULL);
	next_line = extract_lines(lines);
	if (!next_line)
	{
		free(lines);
		lines = NULL;
		return (NULL);
	}
	lines = update_lines(lines);
	return (next_line);
}
