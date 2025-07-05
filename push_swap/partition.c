// #include "push_swap.h"

// void partition(t_stack **a, t_stack **b, int len)
// {
//     int pivot;
//     int pushed;
//     int rotations;
//     int count;

//     if (len <= 1 || is_sorted(a))
//         return;
//     pivot = get_pivot(*a, len);
//     pushed = 0;
//     rotations = 0;
//     count = len / 2 + len % 2;
//     printf("%s\n", "quicksort start");
//     while (count-- > 0 && pushed < len / 2)
//     {
//         if ((*a)->value >= pivot)
//         {
//             pb(a, b);
//             pushed++;
//         } 
//         else
//         {
//             ra(a);
//             rotations++;
//         }
//     }
//     printf("%s\n", "quicksort done");
// }