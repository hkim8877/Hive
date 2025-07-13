/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:04:40 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:04:46 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_cost(int a_cost, int b_cost)
{
	if ((a_cost > 0 && b_cost > 0) || (a_cost < 0 && b_cost < 0))
	{
		if (ft_abs(a_cost) > ft_abs(b_cost))
			return (ft_abs(a_cost));
		else
			return (ft_abs(b_cost));
	}
	else
	{
		return (ft_abs(a_cost) + ft_abs(b_cost));
	}
}

t_costs	push_cost(t_stack **a, t_stack **b, int value_to_push)
{
	t_costs	result;
	int		b_idx;
	int		a_target_idx;

	b_idx = find_index(b, value_to_push);
	a_target_idx = find_target_index_a(a, value_to_push, 0);
	result.a_cost = rotation_cost(a, a_target_idx);
	result.b_cost = rotation_cost(b, b_idx);
	result.total_cost = total_cost(result.a_cost, result.b_cost);
	return (result);
}

static void	combined(t_stack **a, t_stack **b, int *a_cost, int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		rr(a, b);
		(*a_cost)--;
		(*b_cost)--;
	}
	while (*a_cost < 0 && *b_cost < 0)
	{
		rrr(a, b);
		(*a_cost)++;
		(*b_cost)++;
	}
}

static void	best_cost(t_stack **a, t_stack **b, int a_cost, int b_cost)
{
	combined(a, b, &a_cost, &b_cost);
	while (a_cost > 0)
	{
		ra(a);
		a_cost--;
	}
	while (a_cost < 0)
	{
		rra(a);
		a_cost++;
	}
	while (b_cost > 0)
	{
		rb(b);
		b_cost--;
	}
	while (b_cost < 0)
	{
		rrb(b);
		b_cost++;
	}
	pa(a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*current_b_node;
	t_costs	current_costs;
	int		min_total_cost;
	int		best_a_cost;
	int		best_b_cost;

	min_total_cost = INT_MAX;
	best_a_cost = 0;
	best_b_cost = 0;
	if (!*b)
		return ;
	current_b_node = *b;
	while (current_b_node)
	{
		current_costs = push_cost(a, b, current_b_node->value);
		if (current_costs.total_cost < min_total_cost)
		{
			min_total_cost = current_costs.total_cost;
			best_a_cost = current_costs.a_cost;
			best_b_cost = current_costs.b_cost;
		}
		current_b_node = current_b_node->next;
	}
	best_cost(a, b, best_a_cost, best_b_cost);
}
