#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2 || !argv[1][0])
        return (1);
    t_stack *a = NULL;
    t_stack *b = NULL;
    int i;
    char **split_argv = NULL;  
    if (argc == 2)
    {
        split_argv = ft_split(argv[1], ' ');
        argv = split_argv;
        argc = 1;
        while (argv[argc]) 
            argc++;
    }
    i = 1;
    while (i < argc)
    {
        stack_init(&a, ft_atol(argv[i]));  
        i++;
    }
    push_swap(a, b);
    if (split_argv)
    {
        i = 0;
        while (split_argv[i])
            free(split_argv[i++]);
        free(split_argv);
    }
    free_stack(a);
    free_stack(b);
    return (0);
}
