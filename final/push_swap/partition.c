/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:06:59 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:07:01 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_rotate(t_stack **a, t_stack **b, int first, int second)
{
	if ((*a)->value < first)
	{
		pb(a, b);
		rb(b);
	}
	else if ((*a)->value < second)
		pb(a, b);
	else
		ra(a);
}

void	partition(t_stack **a, t_stack **b, int len)
{
	int	first;
	int	second;
	int	count;

	if (len <= 3)
	{
		sort_small(a);
		return ;
	}
	count = len;
	first = get_pivot(*a, len, 1, 1);
	second = get_pivot(*a, len, 2, 1);
	while (count > 0)
	{
		push_rotate(a, b, first, second);
		count--;
	}
}

void	final_push_b(t_stack **a, t_stack **b)
{
	int	cmp;

	if (stack_size(a) <= 3)
	{
		sort_small(a);
		return ;
	}
	cmp = get_pivot(*a, stack_size(a), 3, 3);
	while (stack_size(a) > 3)
	{
		if ((*a)->value < cmp)
			pb(a, b);
		else
			ra(a);
	}
}
