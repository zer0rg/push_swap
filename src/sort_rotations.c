/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:00:00 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/11 18:00:48 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Ejecuta rotaciones simultáneas de A y B
static void	execute_double_rotations(t_stacks *stacks, int *n_rot_a,
		int *n_rot_b, int *directions)
{
	while (*n_rot_a > 0 && *n_rot_b > 0 && directions[0] && directions[1])
	{
		rotate_a_b(stacks);
		(*n_rot_a)--;
		(*n_rot_b)--;
	}
	while (*n_rot_a > 0 && *n_rot_b > 0 && !directions[0] && !directions[1])
	{
		reverse_rot_a_b(stacks);
		(*n_rot_a)--;
		(*n_rot_b)--;
	}
}

// Ejecuta rotaciones restantes de A y B
static void	execute_single_rotations(t_stacks *stacks, int n_rot_a, int n_rot_b,
		int *directions)
{
	while (n_rot_a-- > 0)
	{
		if (directions[0])
			rotate_a(stacks, 1);
		else
			reverse_rot_a(stacks, 1);
	}
	while (n_rot_b-- > 0)
	{
		if (directions[1])
			rotate_b(stacks, 1);
		else
			reverse_rot_b(stacks, 1);
	}
}

// Calcula y ejecuta las rotaciones necesarias
void	execute_rotations(t_stacks *stacks, t_cost cost)
{
	int	n_rot_a;
	int	n_rot_b;
	int	directions[2];

	directions[0] = (cost.pos_a <= (int)stacks->size_a / 2);
	directions[1] = (cost.pos_b <= (int)stacks->size_b / 2);
	if (directions[0])
		n_rot_a = cost.pos_a;
	else
		n_rot_a = (int)stacks->size_a - cost.pos_a;
	if (directions[1])
		n_rot_b = cost.pos_b;
	else
		n_rot_b = (int)stacks->size_b - cost.pos_b;
	execute_double_rotations(stacks, &n_rot_a, &n_rot_b, directions);
	execute_single_rotations(stacks, n_rot_a, n_rot_b, directions);
}
