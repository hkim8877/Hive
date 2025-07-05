#include "push_swap.h"

void bubble_sort(int *arr, int len)
{
    int i;
    int swap;
    int tmp;

    i = 0;
    swap = 1;
    while (swap)
    {
        swap = 0;
        i = 0;
        while (i < len - 1) {
            if (arr[i] > arr[i + 1]) 
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swap = 1;
            }
            i++;
        }
    }
}
int get_pivot(t_stack *stack, int len)
{
    if (!stack || len < 1 || len > stack->size)
        return (0); 

    int *values;
    t_node *current;
    int i;
    int pivot;

    values = malloc(sizeof(int) * len);
    if (!values)
        return (0);
    current = stack->top;
    i = 0;
    while (i < len && current)
    {
        values[i] = current->value;
        current = current->next;
        i++;
    }
    bubble_sort(values, len);
    pivot = values[len / 2];
    free(values);
    return pivot;
}
int rotation_cost(t_stack *stack, int index)
{
    if (!stack || index < 0)
        return (0);
    int size;

    size = stack_size(stack);
    if (index <= size / 2)
        return (index); 
    else
        return (index - size); 
}

// int get_pivot(t_stack *stack, int len)
// {
//     if (!stack || len < 1) 
//         return (0);
//     int first = stack->top->value;
//     int mid = stack->top->value;
//     int last = stack->top->value;
//     int i = 0;
//     t_node *current = stack->top;
//     while (i < (len / 2) && current)
//     {
//         current = current->next;
//         i++;
//     }
//     if (current) 
//         mid = current->value;
//     current = stack->top;
//     while (current->next) 
//         current = current->next;
//     last = current->value;

//     if (((first > mid) && (first < last)) || ((first < mid) && (first > last))) 
//         return (first);
//     else if (((mid > first) && (mid < last)) || ((mid < first) && (mid > last))) 
//         return (mid);
//     else
//         return (last);
// }