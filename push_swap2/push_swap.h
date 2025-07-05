#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    int size;
    int index;
    int cost;
    struct s_stack *next;
} t_stack;

// Push Swap operations
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void push(t_stack **dest, t_stack **src);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

// Utils
int is_sorted(t_stack *stack);
int find_index(t_stack *stack, int value);
int find_target_index(t_stack *stack, int value);
int rotation_cost(t_stack *stack, int index);
int stack_min(t_stack *stack);
int stack_max(t_stack *stack);
int stack_size(t_stack *stack);
int abs(int c);
int get_pivot(t_stack *stack, int len);
void run_cmd(t_stack *a, t_stack *b, t_cost cost);
t_cost calculate_move(t_stack *a, t_stack *b, int value);

//Algorithm
void sort_three(t_stack *a);
void sort_small(t_stack *a);
// void sort_five(t_stack *a, t_stack *b);
void quicksort(t_stack *a, t_stack *b, int len);
void greedy_insert(t_stack *a, t_stack *b);
void push_swap(t_stack *a, t_stack *b);

// Parsing
int ft_atol(char *str);
void stack_init(t_stack *stack, int value);
t_stack *stack_create(void);
void    free_stack(t_stack **stack);
int clean_exit(t_stack **a, t_stack **b, char **split, int exit_code);
int check_duplicate(t_stack *a);
void error(void);
int cleanup_and_error(t_stack **a, t_stack **b);

#endif