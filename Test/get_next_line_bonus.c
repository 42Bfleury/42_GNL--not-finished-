/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:07:26 by bfleury           #+#    #+#             */
/*   Updated: 2024/04/21 21:37:09 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*print_line(char **tempo)
{
	int		i;
	char	*line;
	char	*str;

	if (!*tempo)
		return (NULL);
	str = *tempo;
	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	line = ft_strdup(str, i);
	*tempo = ft_strdup(str + i, ft_strlen(str + i));
	if (str)
		free(str);
	str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tempo[1024];
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(tempo[fd]), tempo[fd] = NULL, NULL);
	if (ft_strchr(tempo[fd], '\n'))
		return (print_line(&tempo[fd]));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		tempo[fd] = ft_strjoin(tempo[fd], buffer);
		if (ft_strchr(tempo[fd], '\n'))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&tempo[fd]));
}
