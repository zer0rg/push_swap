/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:06:05 by rgerman-          #+#    #+#             */
/*   Updated: 2025/11/27 21:32:11 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*args_to_list(char **args)
{
	t_list	*stack;
	t_list	*new_node;
	int		*n;
	stack = NULL;
	while (*args)
	{
		n = malloc(sizeof(int));
		if (!n)
			return(NULL);
		*n = ft_atoi(*args);
		new_node = ft_lstnew(n);
		if (!new_node)
		{
			ft_lstclear(&stack, free);
			return (NULL);
		}
		ft_lstadd_back(&stack, new_node);
		args++;
	}
	return (stack);
}
