/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:07:26 by bfleury           #+#    #+#             */
/*   Updated: 2024/04/26 16:20:32 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_get_line(char **data)
{
	int		i;
	char	*tmp;
	char	*line;

	if (!*data)
		return (NULL);
	tmp = *data;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = ft_strdup(tmp, i);
	if (!line)
		return (free(*data), *data = NULL, NULL);
	if (tmp[i])
	{
		*data = ft_strdup(tmp + i, ft_strlen(tmp + i));
		if (!*data)
			return (free(line), line = NULL, NULL);
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

	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0 || read(fd, buffer, 0) < 0)
		return (free(buffer), buffer = NULL, free(data), data = NULL, NULL);
	if (ft_strchr(data, '\n'))
		return (free(buffer), buffer = NULL, _get_line(&data));
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = 0;
		data = ft_strjoin(data, buffer);
		if (!data)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, _get_line(&data));
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("bible.txt", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (0);
}*/
