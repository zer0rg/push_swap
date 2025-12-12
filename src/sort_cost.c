/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:00:00 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/11 18:03:17 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	calc_individual_costs(t_cost *cost, t_stacks *stacks, int pos_a)
{
	if (pos_a <= (int)stacks->size_a / 2)
		cost->cost_a = pos_a;
	else
		cost->cost_a = stacks->size_a - pos_a;
	if (cost->pos_b < 0)
		cost->cost_b = 0;
	else if (cost->pos_b <= (int)stacks->size_b / 2)
		cost->cost_b = cost->pos_b;
	else
		cost->cost_b = stacks->size_b - cost->pos_b;
}

static int	same_direction(t_stacks *stacks, int pos_a, int pos_b)
{
	int	a_forward;
	int	b_forward;

	a_forward = (pos_a <= (int)stacks->size_a / 2);
	b_forward = (pos_b <= (int)stacks->size_b / 2);
	return (a_forward == b_forward);
}

t_cost	calc_cost(t_stacks *stacks, int pos_a, int target_b)
{
	t_cost	cost;

	cost.pos_a = pos_a;
	cost.target = target_b;
	cost.pos_b = find_pos_by_value(stacks->b, target_b);
	calc_individual_costs(&cost, stacks, pos_a);
	if (cost.pos_b >= 0 && same_direction(stacks, pos_a, cost.pos_b))
	{
		if (cost.cost_a > cost.cost_b)
			cost.total = cost.cost_a;
		else
			cost.total = cost.cost_b;
	}
	else
		cost.total = cost.cost_a + cost.cost_b;
	return (cost);
}

t_cost	find_cheapest_move(t_stacks *stacks)
{
	t_list	*tmp_a;
	int		pos;
	int		target;
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
