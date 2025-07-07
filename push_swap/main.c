#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    t_stack *a;
    t_stack *b;
    int i;
    
    a = NULL;
    b = NULL;
    i = 1;
    while (i < argc)
    {
        stack_init(&a, ft_atol(argv[i]));
        i++;
    }
    // print_stacks_debug("Initial State in main", a, b);
    if (check_duplicate(a))
        return(cleanup_and_error(&a, &b));
    if (!is_sorted(&a))
        push_swap(&a, &b);
    t_stack *current = a;
    t_stack *cur =b;
    // printf("a size: %d\n", stack_size(&a));
    // printf("b size: %d\n", stack_size(&b)); 
    // printf("Stack 'a' contents:\n");
    // while (current != NULL) 
    // {
    //     printf("%d\n", current->value);
    //     current = current->next;
    // }
    // printf("Stack 'b' contents:\n");
    // while (cur != NULL) 
    // {
    //     printf("%d\n", cur->value);
      
    //     current = cur->next;
    // }
    free_stack(&a);
    free_stack(&b);
    return (0);
}



// void print_one_stack(const char *name, t_stack *s) {
//     printf("Stack %s: [", name);
//     if (!s) {
//         printf("EMPTY]\n");
//         return;
//     }
//     t_stack *current = s;
//     while (current) {
//         printf("%d", current->value);
//         if (current->next) {
//             printf(" -> ");
//         }
//         current = current->next;
//     }
//     printf("]\n");
// }

// Function to print both stacks with a message
// void print_stacks_debug(const char *message, t_stack *a, t_stack *b) {
//     printf("\n--- %s ---\n", message);
//     print_one_stack("A", a);
//     print_one_stack("B", b);
//     printf("-----------------\n");
// }