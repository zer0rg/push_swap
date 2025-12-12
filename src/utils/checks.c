/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:19:05 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 22:13:14 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	check_sort(t_stacks *stacks)
{
	t_list	*node;

	if (stacks->size_b > 0)
		return (0);
	node = stacks->a;
	while (node && node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	check_duplicates(t_list *node, long n)
{
	t_list	*tmp;

	tmp = node;

	while (tmp)
	{
		if (*(long *)tmp->content == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	validate_args(char **args)
{
	int		i;
	char	**original;

	original = args;
	while (*args)
	{
		i = 0;
		if ((*args)[i] == '-' || (*args)[i] == '+')
			i++;
		if (!(*args)[i])
			return (0);
		while ((*args)[i])
		{
			if (!ft_isdigit((*args)[i]))
				return (0);
			i++;
		}
		args++;
	}
	return (1);
}
