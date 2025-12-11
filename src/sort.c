/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:32:18 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/11 16:07:36 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Encuentra la posición del mínimo en A
static int	find_min_pos(t_stacks *stacks)
{
	t_list	*tmp;
	int		min_pos;
	int		i;
	int		min_val;

	min_pos = 0;
	tmp = stacks->a;
	i = 0;
	min_val = *(int *)stacks->a->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min_val)
		{
			min_val = *(int *)tmp->content;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

// Rota A para poner el mínimo al top
static void	final_rotate_a(t_stacks *stacks)
{
	int	min_pos;
	int	rotations;

	min_pos = find_min_pos(stacks);
	if (min_pos <= (int)stacks->size_a / 2)
	{
		while (min_pos-- > 0)
			rotate_a(stacks, 1);
	}
	else
	{
		rotations = stacks->size_a - min_pos;
		while (rotations-- > 0)
			reverse_rot_a(stacks, 1);
	}
}

// Retorna b a A con rotaciones optimizadas
static void	push_back_from_b(t_stacks *stacks)
{
	t_max_n	*max;
	int		rotations;

	while (stacks->size_b > 0)
	{
		max = max_on_stack(stacks->b);
		if (max->pos <= (int)stacks->size_b / 2)
		{
			while (max->pos-- > 0)
				rotate_b(stacks, 1);
		}
		else
		{
			rotations = stacks->size_b - max->pos;
			while (rotations-- > 0)
				reverse_rot_b(stacks, 1);
		}
		push_to_a(stacks);
		free(max);
	}
}

// Algoritmo turk: empuja cada elemento de A con costo mínimo
static void	turk_algorithm(t_stacks *stacks)
{
	t_cost	cheapest;

	while (stacks->size_a > 0)
	{
		cheapest = find_cheapest_move(stacks);
		execute_rotations(stacks, cheapest);
		push_to_b(stacks);
	}
}

// Función principal de ordenamiento
bool	init_sorting(t_stacks *stacks)
{
	if (handle_small_cases(stacks))
		return (true);
	push_to_b(stacks);
	push_to_b(stacks);
	turk_algorithm(stacks);
	push_back_from_b(stacks);
	final_rotate_a(stacks);
	return (true);
}
