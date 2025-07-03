#include "push_swap.h"

void quicksort(t_stack *a, t_stack *b, int len)
{
    if (len <= 1 || is_sorted(a))
        return;
    int pivot = get_pivot(a, len);
    int pushed = 0;
    int rotations = 0;
    while (pushed < len / 2)
    {
        if (a->top->value > pivot)
        {
            ra(a);
            rotations++;
        }
        else
        {
            pb(&a, &b);
            pushed++;
        }
    }
    while (rotations--)
        rra(a);
    quicksort(a, b, len - pushed);
    quicksort(b, a, pushed);
    while (pushed--)
        pa(&a, &b);
}
