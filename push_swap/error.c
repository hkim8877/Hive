/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:05:35 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:05:37 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_duplicate(t_stack *a)
{
	t_stack	*next_node;

	while (a)
	{
		next_node = a->next;
		while (next_node)
		{
			if (next_node->value == a->value)
				return (1);
			next_node = next_node->next;
		}
		a = a->next;
	}
	return (0);
}

int	cleanup_and_error(t_stack **a, t_stack **b, char **args, int split)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	if (split)
		free_split(args);
	write(2, "Error\n", 6);
	return (1);
}

void	free_error(t_stack **a)
{
	free_stack(a);
	error();
}
