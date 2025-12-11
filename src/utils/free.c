/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:31:40 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/11 16:46:18 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack->content);
		free(stack);
		stack = tmp;
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		free_stack(stacks->a);
	if (stacks->b)
		free_stack(stacks->b);
	free(stacks);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

