/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:57:16 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/03 13:03:28 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *add, int c, unsigned int n)
{
	unsigned char	*p;

	p = (unsigned char *)add;
	while (n--)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (add);
}
