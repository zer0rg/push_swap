/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:30:49 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/11 17:00:13 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Encuentra la posición de un valor en un stack
int	find_pos_by_value(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
// Encuentra el target de un elemento de A en B
int	find_target(t_list *a_elem, t_list *b)
{
	int	a_val;
	int	best_target;
	int	target;

	a_val = *(int *)a_elem->content;
	best_target = INT_MIN;
	while (b)
	{
		target = *(int *)b->content;
		if (target < a_val && target > best_target)
			best_target = target;
		b = b->next;
	}
	if (best_target == INT_MIN)
	{
		b = a_elem;
		while (b)
		{
			target = *(int *)b->content;
			if (target > best_target)
				best_target = target;
			b = b->next;
		}
	}
	return (best_target);
}
// Encuentra el elemento maximo en el stack
t_max_n	*max_on_stack(t_list *stack)
{
	t_max_n	*max;
	int		i;

	max = malloc(sizeof(t_max_n));
	if (!max)
		return (NULL);
	max->max = INT_MIN;
	i = 0;
	while (stack != NULL)
	{
		if (*(int *)stack->content > max->max)
		{
			max->max = *(int *)stack->content;
			max->pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (max);
}

t_stacks	*init_stacks(char **args)
{
	t_stacks	*stacks;
	t_max_n		*max;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = args_to_list(args);
	stacks->size_a = ft_lstsize(stacks->a);
	stacks->b = NULL;
	stacks->size_b = 0;
	stacks->moves_count = 0;
	stacks->fd = 1;
	max = max_on_stack(stacks->a);
	stacks->max_n = max->max;
	free(max);
	return (stacks);
}
