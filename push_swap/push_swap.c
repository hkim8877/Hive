#include "push_swap.h"

void sort_three(t_stack **a)
{
    if (stack_min(a) == (*a)->value)
    {
        rra(a);  
        sa(a);   
    }
    else if (stack_max(a) == (*a)->value)
    {
        ra(a); 
        if (!is_sorted(a))
            sa(a);  
    }
    else
    {
        if (find_index(a, stack_max(a)) == 1)
            rra(a);
        else
            sa(a);
    }
}

void sort_small(t_stack **a)
{
    if ((*a)->size == 2 && (*a)->value > (*a)->next->value)
        sa(a);
    else if ((*a)->size == 3)
        sort_three(a);
}

// void sort_five(t_stack **a, t_stack **b)
// {
    
// }

void push_swap(t_stack **a, t_stack **b)
{
    if ((*a)->size <= 3)
    {
        sort_small(a);
        return;
    }
    while ((*a)->size > 3)
        quicksort(a, b, (*a)->size);
    if ((*a)->size <= 3)
        sort_small(a);
    greedy_insert(a, b);
    // if (a->size == 4 || a->size == 5)
    // {
    //     sort_five(a);
    //     return;
    // }
    
    // while (b->size > 0)
    //     greedy_insert(a, b);
    // int min_pos;
    // int cost;
    
    // min_pos = find_index(a, INT_MIN);
    // cost = rotation_cost(a, min_pos);
    // while (cost > 0)
    // { 
    //         ra(a); 
    //         cost--;
    // }
    // while (cost < 0)
    // { 
    //     rra(a);
    //     cost++;
    // }
}