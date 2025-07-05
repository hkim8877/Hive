#include "push_swap.h"

void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int check_duplicate(t_stack *a, int c)
{
    t_node *current;

    if (!a || !a->top)
        return (0);
    current = a->top;
    while (current)
    {
        if (current->value == c)
            return (1);
        current = current->next;
    }
    return (0);
}
