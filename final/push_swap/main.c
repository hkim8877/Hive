/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silve <silve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:04:53 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/07/11 18:36:27 by silve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_argv(int argc, char **argv, int *split)
{
	if (argc == 2)
	{
		*split = 1;
		if (!*argv[1])
			error();
		return (ft_split(argv[1], ' '));
	}
	return (argv);
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	init_error(t_stack **a, char **args, int split)
{
	free_stack(a);
	if (split)
		free_split(args);
	error();
	return (0);
}

static int	init_stack_from_args(t_stack **a, char **args, int split)
{
	int			start;
	long long	value;
	int			i;

	if (split)
		start = 0;
	else
		start = 1;
	i = start;
	while (args[i])
	{
		if (check_errors(args[i]))
			init_error(a, args, split);
		value = ft_atol(args[i]);
		if (value > INT_MAX || value < INT_MIN)
			init_error(a, args, split);
		stack_init(a, value);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**splited;
	int		split;

	a = NULL;
	b = NULL;
	split = 0;
	if (argc < 2)
		return (1);
	splited = parse_argv(argc, argv, &split);
	if (!splited)
		return (1);
	if (!init_stack_from_args(&a, splited, split))
		return (cleanup_and_error(&a, &b, splited, split));
	if (check_duplicate(a))
		return (cleanup_and_error(&a, &b, splited, split));
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (split)
		free_split(splited);
	return (0);
}
