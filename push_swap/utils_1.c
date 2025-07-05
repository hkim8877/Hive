#include "push_swap.h"

// static void bubble_sort(int *arr, int len)
// {
//     int i;
//     int swap;
//     int tmp;

//     i = 0;
//     swap = 1;
//     while (swap)
//     {
//         swap = 0;
//         i = 0;
//         while (i < len - 1)
//         {
//             if (arr[i] > arr[i + 1]) 
//             {
//                 tmp = arr[i];
//                 arr[i] = arr[i + 1];
//                 arr[i + 1] = tmp;
//                 swap = 1;
//             }
//             i++;
//         }
//     }
// }
// int get_pivot(t_stack *stack, int len)
// {
//     if (!stack || len < 1)
//         return (0); 

//     int *values;
//     int i;
//     int pivot;

//     values = malloc(sizeof(int) * len);
//     if (!values)
//         return (0);
//     i = 0;
//     while (i < len && stack)
//     {
//         values[i] = stack->value;
//         stack = stack->next;
//         i++;
//     }
//     bubble_sort(values, len);
//     pivot = values[len / 2];
//     free(values);
//     return pivot;
// }
int rotation_cost(t_stack **stack, int index)
{
    if (!stack || !*stack || index < 0)
        return (0);
    int size;

    size = stack_size(stack);
    if (index <= size / 2)
        return (index); 
    else
        return (index - size); 
}

int ft_abs(int c)
{
    if (c < 0)
    {
        c *= -1;
    }
    return (c);
}
void update_idx(t_stack *stack)
{
    int idx;

    idx = 0;
    while (stack)
    {
        stack->index = idx;
        stack = stack->next;
        idx++;
    }
}