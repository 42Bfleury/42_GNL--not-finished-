/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:56:48 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/21 21:38:38 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **str)
{
	int		i;
	char	*tmp;
	char	*line;

	if (!*tmp)
		return (NULL);
	tmp = *str;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = ft_strdup(tmp, i);
	*str = ft_strdup(tmp + i, ft_strlen(tmp + i));
	if (tmp)
		free(tmp);
	tmp = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*buffer;
	int				nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (free(tmp), tmp = NULL, NULL);
	if (ft_strchr(tmp, '\n'))
		return (get_line(&tmp));
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = 0;
		tmp = ft_strjoin(tmp, buffer);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (get_line(&tmp));
}

/*char	*get_next_line(int fd)
{
	static char		*tempo;
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(tempo), tempo = NULL, NULL);
	if (contain_n(tempo))
		return (print_line(&tempo));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		tempo = ft_strjoin(tempo, buffer);
		if (contain_n(tempo))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&tempo));
}*/
