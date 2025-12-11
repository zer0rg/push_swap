/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:03:50 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 14:13:25 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	if (stacks->size_a < 2)
		return ;
	a = *(int *)stacks->a->content;
	b = *(int *)stacks->a->next->content;
	c = *(int *)stacks->a->next->next->content;
	if (a > b && b < c && a < c)
		swap_a(stacks);
	else if (a > b && b > c)
	{
		swap_a(stacks);
		reverse_rot_a(stacks, 1);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stacks, 1);
	else if (a < b && b > c && a < c)
	{
		swap_a(stacks);
		rotate_a(stacks, 1);
	}
	else if (a < b && b > c && a > c)
		reverse_rot_a(stacks, 1);
}

// Maneja caso de 2 elementos
static void	sort_two(t_stacks *stacks)
{
	if (*(int *)stacks->a->content > *(int *)stacks->a->next->content)
		swap_a(stacks);
}

bool	handle_small_cases(t_stacks *stacks)
{
	if (!stacks || !stacks->a)
		return (true);
	if (stacks->size_a <= 1)
		return (true);
	if (stacks->size_a == 2)
	{
		sort_two(stacks);
		return (true);
	}
	if (stacks->size_a == 3)
	{
		sort_three(stacks);
		return (true);
	}
	return (false);
}
