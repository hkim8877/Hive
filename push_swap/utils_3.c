#include "push_swap.h"

int rotation_cost(t_stack **stack, int index)
{
    if (!stack || !*stack || index < 0)
        return (0);
    int size;

    size = stack_size(stack);
    if (index <= size / 2)
        return (index); 
    else
        return (index - size); 
}

int ft_abs(int c)
{
    if (c < 0)
    {
        c *= -1;
    }
    return (c);
}

void update_idx(t_stack *stack)
{
    int idx;

    idx = 0;
    while (stack)
    {
        stack->index = idx;
        stack = stack->next;
        idx++;
    }
}