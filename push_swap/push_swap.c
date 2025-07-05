#include "push_swap.h"

void sort_three(t_stack **a)
{
    int first;
    int second;
    int third;

    first = (*a)->value;
    second = (*a)->next->value;
    third = (*a)->next->next->value;
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a); 
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a); 
}

void sort_small(t_stack **a)
{
    if (stack_size(a) == 2 && (*a)->value > (*a)->next->value)
        sa(a);
    else if (stack_size(a) == 3)
        sort_three(a);
}
void sort_four(t_stack **a, t_stack **b)
{
    int min_index;

    min_index = find_index(a, stack_min(a));
    if (min_index == 0)
        pb(a, b);
    else if (min_index == 1)
    {
        sa(a);
        pb(a, b);
    }
    else if (min_index == 2)
    {
        rra(a);
        pb(a, b);
    }
    else
    {
        rra(a);
        pb(a, b);
    }
    sort_three(a);
    pa(a, b);
}

// void sort_five(t_stack **a, t_stack **b)
// {
    
// }

void push_swap(t_stack **a, t_stack **b)
{
    int a_size;

    a_size = stack_size(a);
    if (a_size <= 3)
    {
        sort_small(a);
        return;
    }
    if (a_size == 4)
    {
        sort_four(a,b);
        return;
    }
    if (a_size > 4 && !is_sorted(a))
    {
        pb(a, b);
        pb(a, b);
    }
    while (stack_size(a) > 3)
    {
        greedy_insert_b(a, b);
    }
    sort_three(a);
    while (*b)
        greedy_insert_a(a, b);
}


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
