#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    if (!stack || !stack->top) 
        return (1);

    t_node *current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return 1;
}
int get_pivot(t_stack *stack, int len)
{
    if (!stack || len < 1) 
        return 0;
    int first = stack->top->value;
    int mid = stack->top->value;
    int last = stack->top->value;
    int i = 0;
    t_node *current = stack->top;
    while (i < (len / 2) && current)
    {
        current = current->next;
        i++;
    }
    if (current) 
        mid = current->value;
    current = stack->top;
    while (current->next) 
        current = current->next;
    last = current->value;

    if (((first > mid) && (first < last)) || ((first < mid) && (first > last))) 
        return (first);
    else if (((mid > first) && (mid < last)) || ((mid < first) && (mid > last))) 
        return (mid);
    else
        return (last);
}

int find_index(t_stack *stack, int value)
{
    if (!stack || !stack->top)
        return -1;

    int index = 0;
    t_node *current = stack->top;
    while (current)
    {
        if (current->value == value)
            return (index);
        current = current->next;
        index++;
    }   
    return -1;
}
int find_target_index(t_stack *stack, int value)
{
    if (!stack || !stack->top)
        return 0;

    int target = 0;
    int min = stack_min(stack);
    int max = stack_max(stack);

    if (value < min || value > max)
        return find_index(stack, min);

    t_node *current = stack->top;
    while (current->next)
    {
        if (value > current->value && value < current->next->value)
            return target + 1;
        current = current->next;
        target++;
    }
    return (0);
}

int compute_rotation_cost(t_stack *stack, int index)
{
    if (!stack || index < 0)
        return 0;
    int size;

    size = stack_size(stack);
    if (index <= size / 2)
        return (index); 
    else
        return (index - size); 
}

int stack_min(t_stack *stack)
{
    if (!stack || !stack->top)
        return (INT_MAX);

    int min = stack->top->value;
    t_node *current = stack->top;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}
int stack_max(t_stack *stack)
{
    if (!stack || !stack->top)
        return INT_MIN;

    int max = stack->top->value;
    t_node *current = stack->top;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}
int stack_size(t_stack *stack)
{
    if (!stack)
        return 0;
    int size;
    t_node *current;

    size = 0;
    current = stack->top;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}