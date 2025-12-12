/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:24:06 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 22:16:20 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;

	args = set_args(argv, argc == 2);
	if (!validate_args(args))
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			free_args(args);
		return (0);
	}
	stacks = init_stacks(args);
	if (!stacks)
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			free_args(args);
		return (0);
	}
	if (check_sort(stacks))
		return (0);
	init_sorting(stacks);
	if (argc == 2)
		free_args(args);
	return (free_stacks(stacks), 0);
}
