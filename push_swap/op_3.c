#include "push_swap.h"

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
void push(t_stack **dest, t_stack **src)
{
    if (!*src)
        return ;
    t_stack *push;
    
    push = *src;
    *src = (*src)->next;
    push->next = *dest;
    *dest = push;
    update_idx(*dest);
    update_idx(*src);
}

void swap(t_stack **stack)
{
     if (!*stack || !(*stack)->next) 
        return;
    t_stack *first;
    t_stack *second;
    int tmp;
        
    first = *stack;
    second = first->next;
    tmp = first->value;
    first->value = second->value;
    second->value = tmp;

    tmp = first->index;
    first->index = second->index;
    second->index = tmp;
}

void rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next) 
        return;
    t_stack *first;
    t_stack *last;
    t_stack *current;
    int index;
    
    first = *stack;
    last = *stack;
    while (last->next) 
        last = last->next;
    *stack = first->next;
    last->next = first;
    current = *stack;
    index = 0;
    while (current)
    {
        current->index = index++;
        current = current->next;
    }
}

void reverse_rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next) 
        return;
    t_stack *last;
    t_stack *prev;
        
    last = *stack;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    update_idx(*stack);
}
