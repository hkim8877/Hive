/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:04:53 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/07 18:04:56 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	i = 1;
	while (i < argc)
	{
		stack_init(&a, ft_atol(argv[i]));
		i++;
	}
	if (check_duplicate(a))
		return (cleanup_and_error(&a, &b));
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
