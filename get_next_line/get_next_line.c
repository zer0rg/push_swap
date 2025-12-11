/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerman- <rgerman-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:21:19 by rgerman-          #+#    #+#             */
/*   Updated: 2025/12/10 20:48:45 by rgerman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_join(char *last, char *new)
{
	char	*join;

	if (!last && !new)
		return (NULL);
	if (!last)
		return (ft_strdup(new));
	if (!new)
		return (last);
	join = ft_strjoin(last, new);
	if (!join)
	{
		free(last);
		return (NULL);
	}
	free(last);
	return (join);
}

char	*read_file(int fd, char *rest)
{
	int		readed_bytes;
	char	*read_buff;

	readed_bytes = 1;
	while (readed_bytes > 0)
	{
		read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!read_buff)
			return (free(rest), NULL);
		readed_bytes = read(fd, read_buff, BUFFER_SIZE);
		if (readed_bytes == -1)
			return (free(read_buff), free(rest), NULL);
		if (readed_bytes == 0)
			return (free(read_buff), rest);
		read_buff[readed_bytes] = '\0';
		rest = free_join(rest, read_buff);
		free(read_buff);
		if (!rest)
			return (NULL);
		if (ft_strchr(rest, '\n'))
			break ;
	}
	return (rest);
}

char	*obtain_line(char **rest)
{
	size_t	i;
	char	*line;
	char	*rest_tmp;

	i = 0;
	if (*rest == NULL)
		return (NULL);
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	line = ft_substr(*rest, 0, i + 1);
	if (!line)
		return (NULL);
	rest_tmp = ft_strdup(*rest + i + 1);
	if (!rest_tmp)
		return (free(line), NULL);
	free(*rest);
	*rest = rest_tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest && ft_strchr(rest, '\n'))
		return (obtain_line(&rest));
	rest = read_file(fd, rest);
	if (rest != NULL && ft_strchr(rest, '\n'))
		line = obtain_line(&rest);
	if (!line)
	{
		if (!rest || !*rest)
			return (free(rest), rest = NULL, NULL);
		line = rest;
		rest = NULL;
		return (line);
	}
	return (line);
}
