/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:24:06 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 20:23:23 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static void	print_result(t_stacks *stacks)
{
	char	*moves_str;

	moves_str = ft_itoa(stacks->moves_count);
	ft_putstr_fd("MOVIMIENTOS: ", 1);
	ft_putstr_fd(moves_str, 1);
	write(1, "\n\n", 2);
	ft_putstr_fd("STACK A: ", 1);
	print_stack(stacks->a);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;

	if (argc == 1)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv+1;
	stacks = init_stacks(args);
	if (!stacks)
		return (1);
	init_sorting(stacks);
	return (0);
}
