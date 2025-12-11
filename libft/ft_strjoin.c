/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:39:27 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/05 21:13:57 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*join;
	size_t	i;

	total_length = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (total_length + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
