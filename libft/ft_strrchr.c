/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:17:24 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/07 20:33:44 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			str_len;
	unsigned char	uc;

	str_len = ft_strlen(str);
	uc = (unsigned char)c;
	if (uc == '\0')
		return ((char *)&str[str_len]);
	while (str_len > 0)
	{
		if (str[str_len - 1] == uc)
			return ((char *)&str[str_len - 1]);
		str_len--;
	}
	return (NULL);
}
