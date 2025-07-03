#include "push_swap.h"

static int ft_isspace(int c)
{
    return((c >= 9 && c <= 13) || c == 32);
}
static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_atol(const char *str)
{
    int sign;
    long long result;

    sign = 1;
    result = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!ft_isdigit(*str))
        write(1, "Error\n", 6);
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
        write(1, "Error\n", 6);
    return ((int)result);
}

