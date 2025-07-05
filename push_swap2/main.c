#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2 || !argv[1][0])
        return (1);
    t_stack *a;
    t_stack *b;
    int i;
    
    a = stack_create();
    b = stack_create();
    if (!a || !b)
        return (1);
    i = 1;
    while (i < argc)
    {
        stack_init(a, ft_atol(argv[i]));
        i++;
    }
    if (check_duplicate(a))
        return(cleanup_and_error(&a, &b));
    if (!is_sorted(a))
        push_swap(a, b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}