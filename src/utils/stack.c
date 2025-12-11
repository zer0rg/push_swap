/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:30:49 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 17:35:37 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	print_stack(t_list *stack)
{ 
	char	*num;

	write(1, "\n", 1);
	while (stack != NULL)
	{
		num = ft_itoa(*(int *)stack->content);
		ft_putstr_fd(num, 1);
		write(1, " ", 1);
		stack = stack->next;
	}
	write(1, "\n", 1);
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
