/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:58:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/10 08:53:20 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			nb_char;
	char		*ptr;
	char		*tmp;
	char		*buffer;
	static char	*data = NULL;

	nb_char		= 0;
	buffer		= ft_strnew(BUFF_SIZE);

	if (fd < 0 || buffer == NULL)
		return (-1);

	while ((nb_char = read(fd, buffer, BUFF_SIZE)) || data)
	{
		if (nb_char < 0)
			return (-1);
		if (data)
		{
			if ((ptr = ft_strchr(data, '\n')))
			{
				*ptr = '\0';
				*line = ft_strdup(data);
				if (*(ptr + 1))
				{
					if (nb_char)
					{
						tmp = ft_strjoin(ptr + 1, buffer);
						ptr = tmp;
					}
					else
						ptr = ft_strdup(ptr + 1);
					ft_strdel(&data);
					data = ptr;
				}
				else
				{
					ft_strdel(&data);
					if (nb_char)
						data = ft_strdup(buffer);
				}
				//if (data)
				//	printf("Data : %s\n", data);
				return (1);
			}
			else
			{
				*line = ft_strdup(data);
				ft_strdel(&data);
			}
		}
		if (nb_char)
		{
			if ((ptr = ft_strchr(buffer, '\n')))
			{
				*ptr = '\0';
				if (*line)
				{
					tmp = ft_strjoin(*line, buffer);
					ft_strdel(line);
					*line = tmp;
				}
				else
					*line = ft_strdup(buffer);
				if (*(ptr + 1))
				{
					if (data)
					{
						tmp = ft_strjoin(data, ptr + 1);
						ft_strdel(&data);
						data = tmp;
					}
					else
						data = ft_strdup(ptr + 1);
				}
				//if (data)
				//	printf("Data : %s\n", data);
				return (1);
			}
			else
			{
				if (data)
				{
					ptr = ft_strjoin(data, buffer);
					ft_strdel(&data);
					data = ptr;
				}
				else
				{
					data = ft_strdup(buffer);
				}
			}
		}
	}
	return (0);
}
