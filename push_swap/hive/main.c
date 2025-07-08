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

static char	**parse_argv(int argc, char **argv, int *split)
{
	if (argc == 2)
	{
		*split = 1;
		return (ft_split(argv[1], ' '));
	}
	return (argv);
}

static int	init_stack_from_args(t_stack **a, char **args, int split)
{
	int		start;
	long	value;
	int		i;

	if (split)
		start = 0;
	else
		start = 1;
	i = start;
	while (args[i])
	{
		if (!check_errors(args[i]))
		{
			value = ft_atol(args[i]);
			stack_init(a, value);
		}
		else
			free_error(a);
		i++;
	}
	return (1);
}

static void	free_split(char **args)
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
#include <stdio.h>
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
		return (cleanup_and_error(&a, &b));
	if (check_duplicate(a))
		return (cleanup_and_error(&a, &b));
	if (!is_sorted(&a))
		push_swap(&a, &b);
	t_stack *current = a;
 	t_stack *cur =b;
    	printf("a size: %d\n", stack_size(&a));
    	printf("b size: %d\n", stack_size(&b)); 
    	printf("Stack 'a' contents:\n");
   	while (current != NULL) 
   	{
   	    printf("%d\n", current->value);
  	     current = current->next;
    	}
   	printf("Stack 'b' contents:\n");
    	while (cur != NULL) 
    	{
        	printf("%d\n", cur->value);
      	        current = cur->next;
    	}
	free_stack(&a);
	free_stack(&b);
	if (split)
		free_split(splited);
	return (0);
}


void print_one_stack(const char *name, t_stack *s) {
    printf("Stack %s: [", name);
    if (!s) {
        printf("EMPTY]\n");
        return;
    }
    t_stack *current = s;
    while (current) {
        printf("%d", current->value);
        if (current->next) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}


void print_stacks_debug(const char *message, t_stack *a, t_stack *b) {
    printf("\n--- %s ---\n", message);
    print_one_stack("A", a);
    print_one_stack("B", b);
    printf("-----------------\n");
}
