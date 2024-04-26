/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:07:26 by bfleury           #+#    #+#             */
/*   Updated: 2024/04/26 22:31:51 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_get_line(char **data)
{
	int		i;
	char	*tmp;
	char	*line;

	tmp = *data;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = ft_gnl_strdup(tmp, i);
	if (!line)
		return (free(*data), *data = NULL, NULL);
	if (tmp[i])
	{
		*data = ft_gnl_strdup(tmp + i, ft_strlen(tmp + i));
		if (!*data)
			return (free(line), line = NULL, free(tmp), tmp = NULL, NULL);
	}
	else
		*data = NULL;
	return (free(tmp), tmp = NULL, line);
}

char	*get_next_line(int fd)
{
	static char		*data;
	char			*buffer;
	int				nb_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (free(data), data = NULL, NULL);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(data), data = NULL, NULL);
	if (ft_strchr(data, '\n'))
		return (free(buffer), buffer = NULL, _get_line(&data));
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = 0;
		data = ft_gnl_strjoin(data, buffer);
		if (!data)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, _get_line(&data));
}
