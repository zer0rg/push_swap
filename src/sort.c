/* ************************************************************************** */
/*       
-                                                                     */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:12:13 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 02:15:31 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Encuentra la posición de un valor en un stack
static int	find_pos_by_value(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
// Encuentra el target de un elemento de A en B
static int	find_target(t_list *a_elem, t_list *b)
{
	int	a_val;
	int	best_target;
	int	target;

	a_val = *(int *)a_elem->content;
	best_target = INT_MIN;
	while (b)
	{
		target = *(int *)b->content;
		if (target < a_val && target > best_target)
			best_target = target;
		b = b->next;
	}
	if (best_target == INT_MIN)
	{
		b = a_elem;
		while (b)
		{
			target = *(int *)b->content;
			if (target > best_target)
				best_target = target;
			b = b->next;
		}
	}
	return (best_target);
}

// Calcula el costo de mover un elemento de A a su target en B
static t_cost	calc_cost(t_stacks *stacks, int pos_a, int target_b)
{
	t_cost	cost;
	int	pos_b;

	cost.pos_a = pos_a;
	cost.target = target_b;
	pos_b = find_pos_by_value(stacks->b, target_b);
	cost.pos_b = pos_b;
	if (pos_a <= (int)stacks->size_a / 2)
		cost.cost_a = pos_a;
	else
		cost.cost_a = stacks->size_a - pos_a;
	if (pos_b < 0)
		cost.cost_b = 0;
	else if (pos_b <= (int)stacks->size_b / 2)
		cost.cost_b = pos_b;
	else
		cost.cost_b = stacks->size_b - pos_b;
	cost.total = cost.cost_a + cost.cost_b;
	return (cost);
}

// Encuentra el movimiento más barato en A
static t_cost	find_cheapest_move(t_stacks *stacks)
{
	t_list	*tmp_a;
	int	pos;
	int	target;
	t_cost	current_cost;
	t_cost	best_cost;

	best_cost.total = INT_MAX;
	tmp_a = stacks->a;
	pos = 0;
	while (tmp_a)
	{
		target = find_target(tmp_a, stacks->b);
		current_cost = calc_cost(stacks, pos, target);
		if (current_cost.total < best_cost.total)
			best_cost = current_cost;
		tmp_a = tmp_a->next;
		pos++;
	}
	return (best_cost);
}

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
static void	execute_single_rotations(t_stacks *stacks, int n_rot_a,
		int n_rot_b, int *directions)
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
static void	execute_rotations(t_stacks *stacks, t_cost cost)
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

// Encuentra la posición del mínimo en A
static int	find_min_pos(t_stacks *stacks)
{
	t_list	*tmp;
	int	min_pos;
	int	i;
	int	min_val;

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
	int	rotations;

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
