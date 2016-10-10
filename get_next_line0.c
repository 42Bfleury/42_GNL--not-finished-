/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:58:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/05 10:38:16 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			length;
	int			nb_char;
	char		*tmp;
	char		*buffer;
	static char	*data = NULL;

	length		= 0;
	nb_char		= 0;
	tmp			= ft_strnew(0);
	buffer		= ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buffer == NULL)
		return (-1);
	printf("data: ");
	if (data)
	{
		printf("%s", data);
		length = ft_strlen(data);
		if (ft_strchr(data, '\n'))
			length = ft_strchr(data, '\n') - data;
		ft_strncpy(tmp, data, length);
		if (length < (int)ft_strlen(data))
			ft_strcpy(data, data + length + 1);
		else
			ft_strdel(&data);
	}
	printf("\nline: %s\n1", *line);
	while ((nb_char = read(fd, buffer, BUFF_SIZE)))
	{
		printf("2");
		if (ft_strchr(buffer, '\n'))
		{
			printf("4");
			length = ft_strchr(buffer, '\n') - buffer;
			if (length < nb_char - 1)
			{
				printf("5");
				data = (data) ? data : ft_strnew(0);
				ft_strcpy(data, ft_strchr(buffer, '\n') + 1);
			}
		}
		else
		{
			printf("6");
			length = nb_char;
		}
		printf("7");
		ft_strncat(tmp, buffer, length);
		if (length != nb_char && ft_strcpy(*line, tmp))
		{
			printf("8\n");
			return (1);
		}
	}
	return (0);
}
