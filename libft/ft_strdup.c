/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:45:25 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/05 21:13:48 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*dup;
	size_t	strlen;

	strlen = ft_strlen(string);
	dup = malloc(sizeof(char) * (strlen + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, string, strlen + 1);
	return (dup);
}
