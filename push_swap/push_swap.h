#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
    int value;
    int index;
    int cost;
    struct s_stack *next;
} t_stack;

typedef struct s_costs
{
    int total_cost;
    int a_rot_cost;
    int b_rot_cost;
} t_costs;

// Push Swap operations
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
void push(t_stack **dest, t_stack **src);
void swap(t_stack **stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);

// Utils
int is_sorted(t_stack **stack);
int find_index(t_stack **stack, int value);
int find_target_index_a(t_stack **stack, int value);
int find_target_index_b(t_stack **stack, int value);
int rotation_cost(t_stack **stack, int index);
int stack_min(t_stack **stack);
int stack_max(t_stack **stack);
int stack_size(t_stack **stack);
int ft_abs(int c);
int get_pivot(t_stack *stack, int len, int pos);
// void run_cmd(t_stack **a, t_stack **b);
// t_costs push_cost_b(t_stack **a, t_stack **b, int value_to_push);
// t_costs push_cost_a(t_stack **a, t_stack **b, int value_to_push);
t_costs calculate_push_costs(t_stack **a, t_stack **b, int value_to_push);
void update_idx(t_stack *stack);

//Algorithm
void sort_three(t_stack **a);
// void sort_four(t_stack **a, t_stack **b);
void sort_small(t_stack **a);
void partition(t_stack **a, t_stack **b, int len);
// void sort_five(t_stack **a, t_stack **b);
// void quicksort(t_stack **a, t_stack **b, int len);
// void greedy_insert_b(t_stack **a, t_stack **b);
void push_swap(t_stack **a, t_stack **b);
int find_three(t_stack **stack_head, int len);
void final_push_b(t_stack **a, t_stack **b);
void greedy_insert_a(t_stack **a, t_stack **b);

// Parsing
int ft_atol(char *str);
t_stack **stack_init(t_stack **stack, int value);
void    free_stack(t_stack **stack);
int clean_exit(t_stack **a, t_stack **b, char **split, int exit_code);
int check_duplicate(t_stack *a);
void error(void);
int cleanup_and_error(t_stack **a, t_stack **b);
t_stack *last(t_stack *stack);

// void print_one_stack(const char *name, t_stack *s);
// void print_stacks_debug(const char *message, t_stack *a, t_stack *b);

#endif