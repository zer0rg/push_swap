/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:48:52 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/01 20:04:33 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	const unsigned char	*ptr;
	unsigned char		casted_chr;

	ptr = (const unsigned char *)buf;
	casted_chr = (unsigned char)c;
	while (count--)
	{
		if (*ptr == casted_chr)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
