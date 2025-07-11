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

int	find_index(t_stack **stack, int value)
{
	int		index;
	t_stack	*current;

	if (!stack)
		return (-1);
	index = 0;
	current = *stack;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	find_target_index_a(t_stack **a, int value, int i)
{
	t_stack	*current;
	t_stack	*next;
	int		target;
	int		a_size;

	if (!*a)
		return (0);
	current = *a;
	target = 0;
	a_size = stack_size(a);
	while (i < a_size)
	{
		next = current->next;
		if (!next)
			next = *a;
		if (value > current->value && value < next->value)
			return (target + 1);
		if (current->value > next->value && (value > current->value
				|| value < next->value))
			return (target + 1);
		current = current->next;
		target++;
		i++;
	}
	return (find_index(a, stack_min(a)));
}

int	stack_min(t_stack **stack)
{
	int		min;
	t_stack	*current;

	if (!stack || !*stack)
		return (INT_MAX);
	min = (*stack)->value;
	current = *stack;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	stack_max(t_stack **stack)
{
	int		max;
	t_stack	*current;

	if (!stack || !*stack)
		return (INT_MIN);
	max = (*stack)->value;
	current = *stack;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*current;

	if (!stack || !*stack)
		return (0);
	size = 0;
	current = *stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
