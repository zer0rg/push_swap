/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:27:07 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 01:42:38 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

bool	push_to_a(t_stacks *stacks)
{
	t_list	*first;

	if (stacks->size_b < 1)
		return (false);
	first = stacks->b;
	stacks->b = stacks->b->next;
	first->next = stacks->a;
	stacks->a = first;
	stacks->size_a += 1;
	stacks->size_b -= 1;
	stacks->moves_count += 1;
	write(stacks->fd, "pa\n", 3);
	return (true);
}

bool	push_to_b(t_stacks *stacks)
{
	t_list	*first;

	if (stacks->size_a < 1)
		return (false);
	first = stacks->a;
	stacks->a = stacks->a->next;
	first->next = stacks->b;
	stacks->b = first;
	stacks->size_a -= 1;
	stacks->size_b += 1;
	stacks->moves_count += 1;
	write(stacks->fd, "pb\n", 3);
	return (true);
}
