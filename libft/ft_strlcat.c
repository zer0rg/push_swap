/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:00:41 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/05 21:13:37 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, int dst_size)
{
	unsigned int	i;
	size_t			src_len;
	size_t			dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if ((size_t)dst_size <= dst_len)
		return ((size_t)dst_size + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < ((size_t)dst_size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
