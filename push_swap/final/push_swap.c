/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:05:14 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:05:16 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_small(t_stack **a)
{
	if (stack_size(a) == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (stack_size(a) == 3)
		sort_three(a);
}

static void	finalize(t_stack **a, int cost)
{
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	a_size;
	int	min_index;
	int	a_cost;

	a_size = stack_size(a);
	if (a_size <= 3)
	{
		sort_small(a);
		return ;
	}
	partition(a, b, stack_size(a));
	if (stack_size(a) > 3)
		final_push_b(a, b);
	sort_small(a);
	while (*b)
		push_to_a(a, b);
	min_index = find_index(a, stack_min(a));
	a_cost = rotation_cost(a, min_index);
	finalize(a, a_cost);
}
