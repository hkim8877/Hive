#include "philosophers.h"

long ft_atol(const char *str)
{
    long result;
    int i = 0;

    result = 0;

    while (str[i] == 32 ||(str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            return (0);
        i++; 
    }
    if (!(str[i] >= '0' && str[i] <= '9'))
    {
        ft_error("Error: invalid input", 1);
        return (0);
    }
    while (str[i] >= '0' && str[i] <= '9')
        result = (result * 10) + (str[i++] - '0');
    return (result);
}

int check_args(int argc, char **argv)
{
    int i;
    long value;

    if (argc < 5 || argc > 6)
        return (0);
    i = 1;
    while (argv[i])
    {
        value = ft_atol(argv[i]);
        if (value <= 0 || value > INT_MAX)
            return (0);
        i++;
    }
    if (ft_atol(argv[1]) > 200)
    {
        ft_error("Error: number of philosophers cannot exceed 200", 0);
        return (0);
    }
    return (1);
}