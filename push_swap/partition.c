#include "push_swap.h"

void partition(t_stack **a, t_stack **b, int len)
{
    if (len <= 3) {
        sort_small(a);
        return;
    }
    int first;
    int second;
    int count = len;
    
    first = get_pivot(*a, len, 1) ;
    second = get_pivot(*a, len, 2);
    // printf("%s\n", "quicksort start");
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
    // printf("%s\n", "before final push");
    int cmp = find_three(a, stack_size(a));
    while (stack_size(a) > 3)
    {
        
        if (cmp > (*a)->value)
            pb(a, b);
        else 
            ra(a);
    }
}
// void final_push_b(t_stack **a, t_stack **b)
// {
//     printf("%s\n", "before final push\n");
//     print_stacks_debug("final_push_b: START", *a, *b); // Initial state of A and B for final_push_b

//     while (stack_size(a) > 3)
//     {
//         int cmp = find_three(a, stack_size(a)); // Recalculate each time
//         printf("  final_push_b loop: A top=%d, current_cmp=%d\n", (*a)->value, cmp); // See what it's comparing
        
//         if (cmp > (*a)->value)
//         {
//             pb(a, b); 
//             printf("  final_push_b loop: PB performed.\n");
//         }
//         else 
//         {
//             ra(a);
//             printf("  final_push_b loop: RA performed.\n");
//         }
//         print_stacks_debug("  final_push_b loop: After operation", *a, *b); // See stacks after each step
//     }
//     print_stacks_debug("final_push_b: END", *a, *b); // Final state from within final_push_b
// }