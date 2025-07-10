/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:07:14 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:07:15 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**stack_init(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*prev;

	if (!stack)
		return (NULL);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->index = 0;
	if (!*stack)
	{
		*stack = new_node;
	}
	else
	{
		prev = last(*stack);
		prev->next = new_node;
	}
	update_idx(*stack);
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
