/*char    *ft_strchr(const char *s, int c)
{
    //unsigned char re;
    unsigned char t;
    int i;

  //  re = (const char)s;
    t = (const char)c;
    i = 0;
    while (!s[i])
    {
        if (s[i] == t)
            return (s);
        i++;
    }
    return (0);
}
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char test[]= "Hello";
    int c = 'e';

    //printf("%c\n", ft_strchr(test, c));
     printf("%s\n", strchr(test,c));
    // printf("%s\n", test);
}