/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:06:05 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 22:12:31 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char	**set_args(char **argv, int n)
{
	char	**args;

	if (!n)
		args = argv + 1;
	else
		args = ft_split(*(argv + 1), ' ');
	return (args);
}

t_list	*args_to_list(char **args)
{
	t_list	*stack;
	t_list	*new_node;
	long	*n;

	stack = NULL;
	while (*args)
	{
		n = malloc(sizeof(long));
		if (!n)
			return (NULL);
		*n = ft_atol(*args);
		if (*n > INT_MAX || *n < INT_MIN || check_duplicates(stack, *n))
			return (ft_lstclear(&stack, free), NULL);
		new_node = ft_lstnew(n);
		if (!new_node)
			return (ft_lstclear(&stack, free), NULL);
		ft_lstadd_back(&stack, new_node);
		args++;
	}
	return (stack);
}

t_stacks	*init_stacks(char **args)
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = args_to_list(args);
	if (!stacks->a)
		return (NULL);
	stacks->size_a = ft_lstsize(stacks->a);
	stacks->b = NULL;
	stacks->size_b = 0;
	stacks->moves_count = 0;
	return (stacks);
}