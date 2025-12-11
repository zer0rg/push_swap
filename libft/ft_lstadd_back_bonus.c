/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:05:06 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/07 19:35:17 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (lst != NULL || new != NULL)
	{
		if (*lst == NULL)
		{
			*lst = new;
			return ;
		}
		copy = *lst;
		while (copy->next != NULL)
			copy = copy->next;
		copy->next = new;
	}
}
