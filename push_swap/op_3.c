#include "push_swap.h"

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
void push(t_stack **dest, t_stack **src)
{
    t_node *push;

    if (!*src || !(*src)->top)
        return ;
    push = (*src)->top;
    (*src)->top = (*src)->top->next;
    push->next = (*dest)->top;
    (*dest)->top = push;
    (*dest)->size++;
    (*src)->size--;
}

void swap(t_stack *stack)
{
    if (stack->size < 2) 
        return;
    int tmp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = tmp;
}

void rotate(t_stack *stack)
{
    if (stack->size < 2) 
        return;
    t_node *last;
    
    last = stack->top;
    while (last->next) 
        last = last->next;
    last->next = stack->top;
    stack->top = stack->top->next;
    last->next->next = NULL;
}

void reverse_rotate(t_stack *stack)
{
    if (stack->size < 2) 
        return;
    t_node *last;
    t_node *prev;

    last = stack->top;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
}
