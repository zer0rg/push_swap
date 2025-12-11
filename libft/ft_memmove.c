/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:38:10 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/03 11:42:21 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int count)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	if (dest_copy == src_copy || count == 0)
		return (dest);
	i = count;
	if (dest_copy > src_copy && dest_copy < src_copy + count)
		while (i-- > 0)
			dest_copy[i] = src_copy[i];
	else
	{
		i = 0;
		while (i < count)
		{
			dest_copy[i] = src_copy[i];
			i++;
		}
	}
	return (dest);
}
