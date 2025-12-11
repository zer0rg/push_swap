/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:59:35 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 14:13:04 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	long_n;
	int		i;

	long_n = n;
	if (n < 0)
		long_n *= -1;
	if (n == 0)
		return (ft_strdup("0"));
	i = digit_counter(n);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = 0;
	while (--i >= 0 && long_n != 0)
	{
		res[i] = (long_n % 10) + '0';
		long_n = (long_n - (long_n % 10)) / 10;
	}
	if (n < 0)
		res[i] = '-';
	while (!((*res >= '0' && *res <= '9') || *res == '-') && *res)
		res++;
	return (res);
}
