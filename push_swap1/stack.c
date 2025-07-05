#include "push_swap.h"

t_stack *stack_create(void)
{
    t_stack *stack;
    
    stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void stack_init(t_stack *stack, int value)
{
    t_node *new_node;
    
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

void    free_stack(t_stack **stack)
{
    t_node  *current;
    t_node  *next_node;

    if (!stack || !*stack)
        return ;
    current = (*stack)->top;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(*stack);
    *stack = NULL;
}

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
    return (1);
}


