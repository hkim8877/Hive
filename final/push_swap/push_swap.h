/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:05:55 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:05:57 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_costs
{
	int	total_cost;
	int	a_cost;
	int	b_cost;
}	t_costs;

// Push Swap operations
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		push(t_stack **dest, t_stack **src);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);

// Utils
int			is_sorted(t_stack **stack);
int			find_index(t_stack **stack, int value);
int			find_target_index_a(t_stack **stack, int value, int i);
int			rotation_cost(t_stack **stack, int index);
int			stack_min(t_stack **stack);
int			stack_max(t_stack **stack);
int			stack_size(t_stack **stack);
void		update_idx(t_stack *stack);
int			ft_abs(int c);
int			get_pivot(t_stack *stack, int len, int pos, int dec);
t_costs		push_cost(t_stack **a, t_stack **b, int value_to_push);

//Algorithm
void		sort_three(t_stack **a);
void		sort_small(t_stack **a);
void		partition(t_stack **a, t_stack **b, int len);
void		final_push_b(t_stack **a, t_stack **b);
void		push_swap(t_stack **a, t_stack **b);
void		push_to_a(t_stack **a, t_stack **b);

// Parsing
long long	ft_atol(char *str);
void		error(void);
int			check_duplicate(t_stack *a);
int			cleanup_and_error(t_stack **a, t_stack **b, char **args, int split);
int			check_errors(char *str);
t_stack		**stack_init(t_stack **stack, int value);
void		free_stack(t_stack **stack);
t_stack		*last(t_stack *stack);
char		**ft_split(char const *s, char c);
void		free_error(t_stack **a);
void		free_split(char **args);

#endif
