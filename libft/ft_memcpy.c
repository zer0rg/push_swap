/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:25:49 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/06 20:17:30 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int count)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;

	if (!dest && !src)
		return (dest);
	src_copy = (unsigned char *)src;
	dest_copy = (unsigned char *)dest;
	while (count--)
	{
		*(dest_copy++) = *(src_copy++);
	}
	return (dest);
}
