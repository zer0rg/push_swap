/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:15:17 by rgerman-          #+#    #+#             */
/*   Updated: 2025/11/21 19:14:46 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

bool	swap_a(t_stacks *stacks)
{
	void	*tmp;

	if (stacks->size_a <= 1)
		return (false);
	tmp = stacks->a->content;
	stacks->a->content = stacks->a->next->content;
	stacks->a->next->content = tmp;
	stacks->moves_count += 1;
	write(stacks->fd, "sa\n", 3);
	return (true);
}

bool	swap_b(t_stacks *stacks)
{
	void	*tmp;

	if (stacks->size_b <= 1)
		return (false);
	tmp = stacks->b->content;
	stacks->b->content = stacks->b->next->content;
	stacks->b->next->content = tmp;
	stacks->moves_count += 1;
	write(stacks->fd, "sb\n", 3);
	return (true);
}

bool	swap_a_b(t_stacks *stacks)
{
	bool	a_res;
	bool	b_res;

	a_res = swap_a(stacks);
	if (!a_res)
		return (false);
	b_res = swap_b(stacks);
	if (!b_res)
	{
		a_res = swap_a(stacks);
		stacks->moves_count -= 2;
		return (false);
	}
	return (true);
}
