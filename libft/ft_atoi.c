/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:46:47 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/06 20:45:48 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *string)
{
	int	is_negative;
	int	result;
	int	i;

	is_negative = 0;
	result = 0;
	i = 0;
	while (string[i] == ' ' || string[i] == '\t' || string[i] == '\v'
		|| string[i] == '\r' || string[i] == '\n' || string[i] == '\f')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			is_negative = 1;
		i++;
	}
	while (string[i] && (string[i] >= '0' && string[i] <= '9'))
	{
		result = (result * 10) + (int)(string[i] - '0');
		i++;
	}
	if (is_negative)
		return (result * (-1));
	return (result);
}
