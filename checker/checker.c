/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:07:02 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 20:53:45 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec_step(char *step, t_stacks *stacks)
{
	if (ft_strncmp(step, "sa\n", 3) == 0)
		return (swap_a(stacks), 1);
	else if (ft_strncmp(step, "sb\n", 3) == 0)
		return (swap_b(stacks), 1);
	else if (ft_strncmp(step, "ss\n", 3) == 0)
		return (swap_a(stacks), swap_b(stacks), 1);
	else if (ft_strncmp(step, "pa\n", 3) == 0)
		return (push_to_a(stacks), 1);
	else if (ft_strncmp(step, "pb\n", 3) == 0)
		return (push_to_b(stacks), 1);
	else if (ft_strncmp(step, "ra\n", 3) == 0)
		return (rotate_a(stacks, 0), 1);
	else if (ft_strncmp(step, "rb\n", 3) == 0)
		return (rotate_b(stacks, 0), 1);
	else if (ft_strncmp(step, "rr\n", 3) == 0)
		return (rotate_a(stacks, 0), rotate_b(stacks, 0), 1);
	else if (ft_strncmp(step, "rra\n", 4) == 0)
		return (reverse_rot_a(stacks, 0), 1);
	else if (ft_strncmp(step, "rrb\n", 4) == 0)
		return (reverse_rot_b(stacks, 0), 1);
	else if (ft_strncmp(step, "rrr\n", 4) == 0)
		return (reverse_rot_a(stacks, 0), reverse_rot_b(stacks, 0), 1);
	return (0);
}

void	check_sort(t_stacks *stacks)
{
	t_list	*node;

	if (stacks->size_b > 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	node = stacks->a;
	while (node && node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		node = node->next;
	}
	write(1, "OK\n", 3);
}

int main(int argc, char **argv)
{
	char	*line;
	t_stacks	*stacks;
	char	**args;
	if (argc == 2)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	stacks = init_stacks(args);
	if (!stacks)
		return (1);
	line = get_next_line(0);
	while(line != NULL)
	{
		exec_step(line, stacks);
		free(line);
		line = get_next_line(0);
	}
	check_sort(stacks);
	return (0);
}
