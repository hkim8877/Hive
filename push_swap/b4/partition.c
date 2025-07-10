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
	first = get_pivot(*a, len, 1);
	second = get_pivot(*a, len, 2);
	while (count > 0)
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
	cmp = find_three(a, stack_size(a));
	while (stack_size(a) > 3)
	{
		if (cmp > (*a)->value)
			pb(a, b);
		else
			ra(a);
	}
}
