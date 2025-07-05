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

int find_target_index(t_stack **stack, int value)
{
    if (!stack)
        return (0);
    int target;
    int min;
    int max;
    t_stack *current;

    target = 0;
    min = stack_min(stack);
    max = stack_max(stack);
    if (value < min || value > max)
        return (find_index(stack, min));
    current = *stack;
    while (current->next)
    {
        if (value > current->value && value < current->next->value)
            return (target + 1);
        current = current->next;
        target++;
    }
    return (0);
}

int stack_min(t_stack **stack)
{
    if (!stack)
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
    if (!stack)
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
    if (!stack)
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