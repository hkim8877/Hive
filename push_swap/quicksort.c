#include "push_swap.h"

static void partition(t_stack **a, t_stack **b, int len)
{
    int count;
    int pivot;
    int pushed;
    int rotations;

    pivot = get_pivot(*a, len);
    count = len;
    pushed = 0;
    rotations = 0;
    while (count-- > 0)
    {
        if ((*a)->value <= pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
            rotations++;
        }
    }
}

static void quick_rotations(t_stack **a, int len, int rotations)
{
    int j;

    if (!a)
        return ;
    if (rotations <= len / 2)
    {
        while (rotations-- > 0)
            rra(a);
    }
    else
    { 
        j = len - rotations;
        while (j-- > 0)
            ra(a);
    }
}

void quicksort(t_stack **a, t_stack **b, int len)
{
    if (len <= 1 || is_sorted(a))
        return;
    partition(a, b, len);
    quick_rotations(a, len, rotations);
    quicksort(a, b, len - pushed);
    if (pushed <= 3)
        sort_small(b);
    else
        quicksort(b, a, pushed);
}