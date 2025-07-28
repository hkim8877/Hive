/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:06:04 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:06:06 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_cost(t_stack **stack, int index)
{
	int	size;

	if (!stack || !*stack || index < 0)
		return (0);
	size = stack_size(stack);
	if (index <= size / 2)
		return (index);
	else
		return (index - size);
}

int	ft_abs(int c)
{
	if (c < 0)
	{
		c *= -1;
	}
	return (c);
}

void	update_idx(t_stack *stack)
{
	int	idx;

	idx = 0;
	while (stack)
	{
		stack->index = idx;
		stack = stack->next;
		idx++;
	}
}
