/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:22:08 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 20:51:56 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

bool	reverse_rot_a(t_stacks *stacks, int write_flag)
{
	t_list	*last;
	t_list	*second_last;

	if (stacks->size_a <= 1)
		return (false);
	second_last = stacks->a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stacks->a;
	stacks->a = last;
	if (write_flag)
	{
		stacks->moves_count += 1;
		write(1, "rra\n", 4);
	}
	return (true);
}

bool	reverse_rot_b(t_stacks *stacks, int write_flag)
{
	t_list	*last;
	t_list	*second_last;

	if (stacks->size_b <= 1)
		return (false);
	second_last = stacks->b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stacks->b;
	stacks->b = last;
	if (write_flag)
	{
		write(1, "rrb\n", 4);
		stacks->moves_count += 1;
	}
	return (true);
}

bool	reverse_rot_a_b(t_stacks *stacks)
{
	reverse_rot_a(stacks, 0);
	reverse_rot_b(stacks, 0);
	stacks->moves_count += 1;
	write(1, "rrr\n", 4);
	return (true);
}
