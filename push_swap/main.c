#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    t_stack *a;
    t_stack *b;
    int i;
    
    a = NULL;
    b = NULL;
    i = 1;
    while (i < argc)
    {
        stack_init(&a, ft_atol(argv[i]));
        i++;
    }
    if (check_duplicate(a))
        return(cleanup_and_error(&a, &b));
    if (!is_sorted(&a))
        push_swap(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}