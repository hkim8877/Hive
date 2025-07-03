#include "push_swap.h"

void sort_small_stack(t_stack *a)
{
    if (a->size == 2 && a->top->value > a->top->next->value)
        sa(a);
    else if (a->size == 3)
    {
        int x = a->top->value;
        int y = a->top->next->value;
        int z = a->top->next->next->value;

        if (x > y && y < z && x < z) 
            sa(a);
        else if (x > y && y > z)
        {
            sa(a);
            rra(a);
        }
        else if (x > y && y < z && x > z)
            ra(a);
        else if (x < y && y > z && x < z)
        {
            sa(a);
            ra(a);
        }
        else if (x < y && y > z && x > z)
            rra(a);
    }
}

void push_swap(t_stack *a, t_stack *b)
{
    if (a->size <= 3)
    {
        sort_small_stack(a);
        return;
    }
    quicksort(a, b, a->size);
    while (b->size > 0)
        greedy_insert(a, b);
    int min_pos;
    int cost;
    
    min_pos = find_index(a, INT_MIN);
    cost = compute_rotation_cost(a, min_pos);
    while (cost > 0)
    { 
            ra(a); 
            cost--;
    }
    while (cost < 0)
    { 
        rra(a);
        cost++;
    }
}