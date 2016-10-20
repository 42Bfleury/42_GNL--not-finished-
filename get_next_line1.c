/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:58:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/19 13:22:27 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*new_elem(int fd)
{
	t_gnl	*elem;

	if (fd < 0 || !(elem = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	elem->fd = fd;
	elem->next = NULL;
	elem->prev = NULL;
	elem->data = NULL;
	return (elem);
}

t_gnl		*check_lst(t_gnl **first, int fd)
{
	t_gnl	*elem;

	elem = *first;
	while (elem->next)
	{
		if (elem->fd == fd)
			return (elem);
		elem = elem->next;
	}
	if (elem->fd == fd)
		return (elem);
	elem->next = new_elem(fd);
	elem->next->prev = elem;
	return (elem->next);
}

int			check_data(char **data, char **line)
{
	char	*tmp;

	if (*data && (tmp = ft_strchr(*data, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*data);
		tmp = (*(tmp + 1)) ? ft_strdup(tmp + 1) : NULL;
		ft_strdel(data);
		*data = tmp;
		return (1);
	}
	return (0);
}

int			del_elem(t_gnl **elem, char **line)
{
	if ((*elem)->data && *(*elem)->data)
	{
		*line = ft_strdup((*elem)->data);
		ft_strdel(&(*elem)->data);
		return (1);
	}
	if (!(*elem)->data)
	{
		if ((*elem)->prev)
			(*elem)->prev->next = (*elem)->next;
		if ((*elem)->next)
			(*elem)->next->prev = (*elem)->prev;
		free(*elem);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*first = NULL;
	t_gnl			*elem;
	char			*tmp;
	char			buffer[BUFF_SIZE + 1];
	int				nb_char;

	first = (first) ? first : new_elem(fd);
	if (!first || !line || fd < 0)
		return (-1);
	elem = check_lst(&first, fd);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((nb_char = read(fd, buffer, BUFF_SIZE)) || elem->data)
	{
		if (nb_char < 0)
			return (-1);
		if (nb_char)
		{
			tmp = (elem->data) ? ft_strjoin(elem->data, buffer) : ft_strdup(buffer);
			ft_strdel(&elem->data);
			elem->data = tmp;
		}
		if (check_data(&elem->data, line))
			return (1);
	}
	return (del_elem(&elem, line));
}
