/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:30:49 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 20:01:20 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

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

int	find_min_pos(t_stacks *stacks)
{
	t_list	*tmp;
	int		min_pos;
	int		i;
	int		min_val;

	min_pos = 0;
	tmp = stacks->a;
	i = 0;
	min_val = *(int *)stacks->a->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min_val)
		{
			min_val = *(int *)tmp->content;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

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

