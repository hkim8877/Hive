#include "push_swap.h"

int find_index(t_stack **stack, int value)
{
    if (!stack)
        return (-1);
    int index;
    t_stack *current;

    index = 0;
    current = *stack;
    while (current)
    {
        if (current->value == value)
            return (index);
        current = current->next;
        index++;
    }   
    return (-1);
}

int find_target_index_a(t_stack **a, int value)
{
    if (!*a)
        return 0;

    t_stack *current = *a;
    t_stack *next;
    int target = 0;
    int a_size = stack_size(a);
    int i = 0;    
    while (i < a_size)
    {
        next = current->next;
        if (!next)
            next = *a; 
        if (value > current->value && value < next->value)
            return (target + 1);
        if (current->value > next->value && (value > current->value || value < next->value))
            return (target + 1);
        current = current->next;
        target++;
        i++;
    }
    return (find_index(a, stack_min(a)));
}

int stack_min(t_stack **stack)
{
    if (!stack || !*stack)
        return (INT_MAX);
    int min;
    t_stack *current;

    min = (*stack)->value;
    current = *stack;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int stack_max(t_stack **stack)
{
    if (!stack || !*stack)
        return INT_MIN;
    int max;
    t_stack *current;

    max = (*stack)->value;
    current = *stack;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int stack_size(t_stack **stack)
{
    if (!stack || !*stack)
        return (0);
    int size;
    t_stack *current;

    size = 0;
    current = *stack;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}
