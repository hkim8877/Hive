#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2 || !argv[1][0])
        return (1);
    t_stack *a;
    t_stack *b;
    int i;
    
    a = stack_create();
    b = stack_create();
    if (!a || !b)
        return (1);
    // if (argc == 2)
    // {
    //     argv = ft_split(argv[1], ' ');
    //     argc = 0;
    //     while (argv[argc])
    //         argc++;
    //     i = 0;
    //  }
    // else
    i = 1;
    while (i < argc)
    {
        stack_init(a, ft_atol(argv[i]));
        i++;
    }
    if (check_duplicate(a))
        return(cleanup_and_error(&a, &b));
    if (!is_sorted(a))
        push_swap(a, b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}


// int main(int argc, char **argv)
// {
//     t_stack *a = malloc(sizeof(t_stack));
//     t_stack *b = malloc(sizeof(t_stack));
//     if (!a || !b)
//         return (1);
//     a->top = NULL;
//     a->size = 0;
//     b->top = NULL;
//     b->size = 0;
//     int i;
     
//     if (argc < 2 || !argv[1][0])
//         return (1);
//     // if (argc == 2)
//     //     argv = ft_split(argv[1], ' ');
//     i = 1;
//     while (i < argc)
//     {
//         stack_init(a, ft_atol(argv[i]));
//         i++;
//     }
//     // printf("%d\n", stack_size(a));
//     push_swap(a, b);
//     free_stack(&a);
//     free_stack(&b);
//     return (0);
// }

// int main(int argc, char **argv)
// {
//     t_stack *a = NULL;
//     // t_stack *b = NULL;
//     int i;
     
//     i = 1;
//     if (argc < 2 || !argv[1][0])
//         return (1);
//     stack_init(&a, ft_atol(argv[i++]));
//     // push_swap(a, b);
//     printf("%d\n", stack_size(t_stack(a)));

//     return (0);
// }
