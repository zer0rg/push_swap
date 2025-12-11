/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:50:06 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/06 13:15:44 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	size_t			str_len;

	if (!s || !f)
		return (NULL);
	str_len = ft_strlen(s);
	res = malloc((str_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
