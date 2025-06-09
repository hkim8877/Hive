#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd = open("short.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	close(fd);
}
