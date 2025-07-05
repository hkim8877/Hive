#include "push_swap.h"

void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
int check_duplicate(t_stack *a)
{
    t_stack *next_node;

    while (a)
    {
        next_node = a->next;
        while (next_node)
        {
            if (next_node->value == a->value)
                return (1);
            next_node = next_node->next;
        }
        a = a->next;
    }
    return (0);
}
int cleanup_and_error(t_stack **a, t_stack **b)
{
    if (a && *a)
        free_stack(a); 
    if (b && *b)
        free_stack(b); 
    write(2, "Error\n", 6);
    return (1);       
}
