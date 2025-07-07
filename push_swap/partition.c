#include "push_swap.h"

void partition(t_stack **a, t_stack **b, int len)
{
    if (len <= 3)
    {
        sort_small(a);
        return;
    }
    int first;
    int second;
    int count = len;
    
    first = get_pivot(*a, len, 1) ;
    second = get_pivot(*a, len, 2);
    while (count > 0)
    {
        if ((*a)->value < first)
        {
            pb(a, b); 
            rb(b);             
        }
        else if ((*a)->value < second)
            pb(a, b); 
        else
            ra(a);
        count--;
    }
}

void final_push_b(t_stack **a, t_stack **b)
{
    if (stack_size(a) <= 3)
    {
        sort_small(a);
        return;
    }
    int cmp;
    
    cmp = find_three(a, stack_size(a));
    while (stack_size(a) > 3)
    {
        if (cmp > (*a)->value)
            pb(a, b);
        else 
            ra(a);
    }
}