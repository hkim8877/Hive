#ifndef GET_NEXXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

# include <unistd.h>
# include <stdlib.h>


char *get_next_line(int fd);
int ft_strlen(const char *str);
char *ft_strchr(const char *str, int c);
char *ft_strdup(const char *src);
char *ft_strjoin(const char *s1, const char *s2);

#endif