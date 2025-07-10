/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:05:28 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:05:29 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int len)
{
	int	i;
	int	swap;
	int	tmp;

	i = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
}

// static int	*sorted(t_stack *stack, int len, int pos)
// {
// 	int		*values;
// 	int		pivot;
// 	int		i;
// 	t_stack	*current;

// 	if (!stack || len < 1)
// 		return (0);
// 	values = malloc(sizeof(int) * len);
// 	if (!values)
// 		return (0);
// 	current = stack;
// 	i = 0;
// 	while (i < len && current)
// 	{
// 		values[i] = current->value;
// 		current = current->next;
// 		i++;
// 	}
// 	bubble_sort(values, len);
// 	return (values);
// }

// int	get_pivot(t_stack *stack, int len, int pos, int dec)
// {
// 	int pivot;

// 	pivot = values[(len * pos / 3) - dec];
// }

int	get_pivot(t_stack *stack, int len, int pos, int dec)
{
	int		*values;
	int		pivot;
	int		i;
	t_stack	*current;

	if (!stack || len < 1)
		return (INT_MIN);
	values = malloc(sizeof(int) * len);
	if (!values)
		return (INT_MIN);
	current = stack;
	i = 0;
	while (i < len && current)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(values, i);
	pivot = values[(i * pos / 3) - dec];
	free(values);
	return (pivot);
}

// static int	check_len(int i, int *values)
// {
// 	int	check;

// 	check = 1;
// 	if (len < 3)
// 	{
// 		free(values);
// 		check = 0;
// 	}
// 	return (check);
// }

// int	find_three(t_stack **stack, int len)
// {
// 	int		*values;
// 	int		i;
// 	int		pivot;
// 	t_stack	*current;

// 	if (!stack || !*stack || len < 3)
// 		return (0);
// 	values = malloc(sizeof(int) * len);
// 	if (!values)
// 		return (INT_MIN);
// 	current = *stack;
// 	i = 0;
// 	while (i < len && current)
// 	{
// 		values[i] = current->value;
// 		current = current->next;
// 		i++;
// 	}
// 	if (i < len)
// 		len = i;
// 	if (len < 3)
// 	{
// 		free(values);
// 		return (INT_MIN);
// 	}
// 	bubble_sort(values, len);
// 	pivot = values[len - 3];
// 	free(values);
// 	return (pivot);
// }