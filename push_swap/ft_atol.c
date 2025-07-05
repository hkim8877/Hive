#include "push_swap.h"

static int ft_isspace(int c)
{
    return((c >= 9 && c <= 13) || c == 32);
}
static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_atol(char *str)
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
    if (!*str || check_error(str))
        error();
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
            error();
        str++;
    }
    return ((int)(result * sign));
}

int check_error(char *str)
{
    if (*str == '+' || *str == '-')
        str++;
    if (!ft_isdigit(*str))
        return (1);
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (1);
        str++;
    }
    return (0);
}