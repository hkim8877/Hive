#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

typedef struct s_cost
{
    int a_index;
    int b_index;
    int a_cost;
    int b_cost;
    int push_cost;
} t_cost;

// Stack operations
void push(t_stack **dest, t_stack **src);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

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

// Utils
int is_sorted(t_stack *stack);
int get_pivot(t_stack *stack, int len);
int find_index(t_stack *stack, int value);
int find_target_index(t_stack *stack, int value);
int compute_rotation_cost(t_stack *stack, int index);
int stack_min(t_stack *stack);
int stack_max(t_stack *stack);
int stack_size(t_stack *stack);

//Algorithm
t_cost calculate_move(t_stack *a, t_stack *b, int value);
void run_cmd(t_stack *a, t_stack *b, t_cost cost);
void greedy_insert(t_stack *a, t_stack *b);
void quicksort(t_stack *a, t_stack *b, int len);
void sort_small_stack(t_stack *a);
void push_swap(t_stack *a, t_stack *b);

// Parsing
char			**ft_split(char const *s, char c);
int ft_atol(char *str);
void stack_init(t_stack *stack, int value);
void    free_stack(t_stack **stack);
int check_error(char *str);
int clean_exit(t_stack **a, t_stack **b, char **split, int exit_code);

#endif