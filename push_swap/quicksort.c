#include "push_swap.h"

void quicksort(t_stack **a, t_stack **b, int len)
{
    int count;
    int pivot;
    int pushed;
    int rotations;

    if (len <= 1 || is_sorted(a))
        return;
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