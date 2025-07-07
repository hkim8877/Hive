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

int find_three(t_stack **stack, int len) // Parameter remains t_stack **stack
{
    // Defensive checks
    if (!stack || !*stack || len < 3) // Check if stack pointer or stack itself is NULL, or too short
        return (0); // Return 0, or an appropriate error code

    int *values;
    int i;
    int pivot;
    t_stack *current; // DECLARE A TEMPORARY POINTER FOR TRAVERSAL

    values = malloc(sizeof(int) * len);
    if (!values)
        return (0); // Error: Memory allocation failed

    i = 0;
    current = *stack; // INITIALIZE TEMPORARY POINTER FROM THE STACK'S HEAD
                      // This 'current' now holds the actual head of the linked list
                      // but it's a local copy, not directly modifying *stack

    while (i < len && current) // Iterate using the temporary 'current' pointer
    {
        values[i] = current->value;
        current = current->next; // Move the temporary 'current' pointer forward
                                 // The original *stack (i.e., *a in final_push_b) remains untouched
        i++;
    }

    // This check is important if 'len' was based on an assumption that might not hold true for 'current'
    // but typically stack_size should accurately reflect 'len'.
    if (i < len) { 
        // This case would mean the list was shorter than 'len' indicated,
        // or a node was NULL unexpectedly before 'len' elements were copied.
        // It's a sign of deeper inconsistency or an edge case.
        // For robustness, adjust len or handle as an error.
        len = i; // Adjust len to the actual number of elements copied
        if (len < 3) { // If after adjustment, it's still too short for find_three
            free(values);
            return 0; 
        }
    }


    bubble_sort(values, len);
    
    // As per previous discussion, values[len - 3] typically gets the 3rd element
    // from the end of the sorted array (which is the third largest if sorted ascending).
    // This seems consistent with its use in final_push_b to identify elements to keep.
    pivot = values[len - 3]; 

    free(values); // Free the allocated memory
    return (pivot);
}

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