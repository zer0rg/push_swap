/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:29:41 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 22:08:57 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_cost
{
	int		cost_a;
	int		cost_b;
	int		total;
	int		pos_a;
	int		pos_b;
	int		target;
}			t_cost;

typedef struct s_maxn
{
	int		max;
	int		pos;
}			t_max_n;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	size_t	size_a;
	size_t	size_b;
	size_t	moves_count;
}			t_stacks;

/*
	Parser
*/
char		**set_args(char **argv, int n);
int			validate_args(char **args);
t_stacks	*init_stacks(char **args);
/*
	Operations
*/
bool		swap_a(t_stacks *stacks);
bool		swap_b(t_stacks *stacks);
bool		swap_a_b(t_stacks *stacks);
bool		push_to_a(t_stacks *stacks);
bool		push_to_b(t_stacks *stacks);
bool		rotate_a(t_stacks *stacks, int write_flag);
bool		rotate_b(t_stacks *stacks, int write_flag);
bool		rotate_a_b(t_stacks *stacks);
bool		reverse_rot_a(t_stacks *stacks, int write_flag);
bool		reverse_rot_b(t_stacks *stacks, int write_flag);
bool		reverse_rot_a_b(t_stacks *stacks);
void		rotate_a_to_top(t_stacks *stacks, int pos_a);
void		rotate_b_to_top(t_stacks *stacks, int pos_b);

/*
	Checks
*/
int			check_sort(t_stacks *stacks);
int			check_duplicates(t_list *node, long n);

/*
	Sorting
*/
bool		init_sorting(t_stacks *stacks);
bool		handle_small_cases(t_stacks *stacks);
t_cost		find_cheapest_move(t_stacks *stacks);
void		execute_rotations(t_stacks *stacks, t_cost cost);

/*
	Stack Utils
*/
t_max_n		*max_on_stack(t_list *stack);
int			find_target(t_list *a_elem, t_list *b);
int			find_pos_by_value(t_list *stack, int value);
int			find_min_pos(t_stacks *stacks);

/*
	Free
*/
void		free_stacks(t_stacks *stacks);
void		free_args(char **args);

#endif