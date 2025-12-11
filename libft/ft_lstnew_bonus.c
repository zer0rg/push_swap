/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:35:56 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/07 18:54:44 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*linked_list;

	linked_list = malloc(sizeof(t_list));
	if (!linked_list)
		return (NULL);
	linked_list->content = content;
	linked_list->next = NULL;
	return (linked_list);
}
