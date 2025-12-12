/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:48:34 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/12 17:50:04 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *string)
{
	int is_negative;
	long result;
	int i;

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
		result = (result * 10) + (long)(string[i] - '0');
		i++;
	}
	if (is_negative)
		return (result * (-1));
	return (result);
}