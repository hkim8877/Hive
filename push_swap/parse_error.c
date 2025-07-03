#include "push_swap.h"

static int ft_isspace(int c)
{
    return((c >= 9 && c <= 13) || c == 32);
}
static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
int ft_atol(char *str)
{
    int sign;
    long long result;
   
    if (!*str || check_error(str))
        error();
    sign = 1;
    result = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
            error();
        str++;
    }
    return ((int)(result * sign));
}

// void stack_init(t_stack **stack, int value)
// {
//     t_node *new_node;
   
//     if (!stack)
//         return ;
//     new_node = malloc(sizeof(t_node));
//     if (!new_node)
//         return ;
//     new_node->value = value;
//     new_node->next = NULL;
//     if (!*stack)
//     {
//         *stack = malloc(sizeof(t_stack));
//         if (!*stack)
//         {
//             free(new_node);
//             return ;
//         }
//         (*stack)->top = new_node;
//         (*stack)->size = 1;
//     }
//     else
//     {
//         new_node->next = (*stack)->top;
//         (*stack)->top = new_node;
//         (*stack)->size +=1;
//     }
// }
t_stack *stack_create(void)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_init(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}


void    free_stack(t_stack **stack)
{
    t_node  *current;
    t_node  *next_node;

    if (!stack || !*stack)
        return;
    current = (*stack)->top;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(*stack);
    *stack = NULL;
}
int check_error(char *str)
{
    if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
        return (1);
    if ((*str == '+' || *str == '-') || !ft_isdigit(*str))
        return (1);
    str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (1);
        str++;
    }
    return (0);
}