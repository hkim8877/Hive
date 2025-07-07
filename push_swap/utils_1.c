#include "push_swap.h"

static void bubble_sort(int *arr, int len)
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
        while (i < len - 1)
        {
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

int get_pivot(t_stack *stack, int len, int pos)
{
    if (!stack || len < 1)
        return (0);
    int *values;
    int i;
    int pivot;

    values = malloc(sizeof(int) * len);
    if (!values)
        return (0);
    i = 0;
    while (i < len && stack)
    {
        values[i] = stack->value;
        stack = stack->next;
        i++;
    }
    bubble_sort(values, len);
    pivot = values[(len * pos / 3) - 1];
    free(values);
    return (pivot);
}

int find_three(t_stack **stack, int len)
{
    if (!stack || !*stack || len < 3)
        return (0);
    int *values;
    int i;
    int pivot;
    t_stack *current;

    values = malloc(sizeof(int) * len);
    if (!values)
        return (0);
    i = 0;
    current = *stack; 
    while (i < len && current)
    {
        values[i] = current->value;
        current = current->next; 
        i++;
    }
    if (i < len)
    {        
        len = i;
        if (len < 3)
        { 
            free(values);
            return 0; 
        }
    }
    bubble_sort(values, len);
    pivot = values[len - 3]; 
    free(values); 
    return (pivot);
}
