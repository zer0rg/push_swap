/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:31:40 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 20:53:50 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		ft_lstclear(&(stacks->a), free);
	if (stacks->b)
		ft_lstclear(&(stacks->b), free);
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