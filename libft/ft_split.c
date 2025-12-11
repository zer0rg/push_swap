/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:17:36 by rgerman-          #+#    #+#             */
/*   Updated: 2025/10/07 20:07:38 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static int		count_chars_insubstr(char const *s, char **str, char c);

static size_t	count_substrs(char *s, char c)
{
	int		in_substr;
	size_t	substrs_count;

	substrs_count = 0;
	while (*s)
	{
		in_substr = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!in_substr)
			{
				in_substr = 1;
				substrs_count++;
			}
			s++;
		}
	}
	return (substrs_count);
}

static int	alloc_substrs(char **strarr, char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	substr_len;

	i = 0;
	while (*s)
	{
		k = 0;
		while (*s == c && *s)
			s++;
		substr_len = count_chars_insubstr(s, &strarr[i], c);
		if (!substr_len)
			return (i);
		while (*s != c && *s && k < substr_len)
		{
			strarr[i][k] = *s++;
			k++;
		}
		strarr[i][k] = 0;
		i++;
	}
	return (1);
}

static int	count_chars_insubstr(char const *s, char **str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		count++;
	}
	if (count == 0)
	{
		*str = NULL;
		return (0);
	}
	*str = malloc(sizeof(char) * (count + 1));
	if (!*str)
		return (0);
	return (count);
}

static void	free_split(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	substrs_count;
	int		succesful_allocs;

	if (NULL == s)
		return (NULL);
	substrs_count = count_substrs((char *)s, c);
	split = malloc((substrs_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[substrs_count] = NULL;
	if (substrs_count > 0)
	{
		succesful_allocs = alloc_substrs(split, s, c);
		if (!succesful_allocs)
		{
			free_split(split, succesful_allocs);
			return (split);
		}
	}
	return (split);
}
