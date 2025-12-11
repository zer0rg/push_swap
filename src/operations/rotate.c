/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:45:21 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 14:16:41 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

bool	rotate_a(t_stacks *stacks, int write_flag)
{
	t_list	*first;

	if (stacks->size_a <= 1)
		return (false);
	first = stacks->a;
	stacks->a = stacks->a->next;
	first->next = NULL;
	ft_lstadd_back(&stacks->a, first);
	if (write_flag)
	{
		write(stacks->fd, "ra\n", 3);
		stacks->moves_count += 1;
	}
	return (true);
}

bool	rotate_b(t_stacks *stacks, int write_flag)
{
	t_list	*first;

	if (stacks->size_b <= 1)
		return (false);
	first = stacks->b;
	stacks->b = stacks->b->next;
	first->next = NULL;
	ft_lstadd_back(&stacks->b, first);
	if (write_flag)
	{
		stacks->moves_count += 1;
		write(stacks->fd, "rb\n", 3);
	}
	return (true);
}

bool	rotate_a_b(t_stacks *stacks)
{
	rotate_a(stacks, 0);
	rotate_b(stacks, 0);
	stacks->moves_count += 1;
	write (1, "rr\n", 3);
	return (true);
}

// Rota A hacia el top
void	rotate_a_to_top(t_stacks *stacks, int pos_a)
{
	int	rotations;

	if (pos_a <= (int)stacks->size_a / 2)
	{
		while (pos_a-- > 0)
			rotate_a(stacks, 1);
	}
	else
	{
		rotations = stacks->size_a - pos_a;
		while (rotations-- > 0)
			reverse_rot_a(stacks, 1);
	}
}

// Rota B hacia el top
void	rotate_b_to_top(t_stacks *stacks, int pos_b)
{
	int	rotations;

	if (pos_b <= 0)
		return ;
	if (pos_b <= (int)stacks->size_b / 2)
	{
		while (pos_b-- > 0)
			rotate_b(stacks, 1);
	}
	else
	{
		rotations = stacks->size_b - pos_b;
		while (rotations-- > 0)
			reverse_rot_b(stacks, 1);
	}
}
