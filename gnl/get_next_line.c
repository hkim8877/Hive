#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *lines = NULL;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = read_file(fd, lines);
}
static char *read_file(int fd, char *lines)
{
	char *buffer;
	char *temp;
	ssize_t byte;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	lines = ft_strdup("");
	while ((byte = read (fd, buffer, BUFFER_SIZE))> 0)
	{
		buffer[byte] = '\0';
		temp = ft_strjoin(lines, buffer);
		free(lines);
		lines = temp;
	}
	free(buffer);
	return (lines);
}

char *extract_line()
{

}
