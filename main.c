/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:24:06 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/11 16:46:17 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;
	int			is_split;

	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	is_split = (argc == 2);
	if (is_split)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	stacks = init_stacks(args);
	if (is_split)
		free_args(args);
	if (!stacks)
		return (1);
	init_sorting(stacks);
	free_stacks(stacks);
	return (0);
}
