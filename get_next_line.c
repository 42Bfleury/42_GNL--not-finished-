/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 00:46:39 by bfleury           #+#    #+#             */
/*   Updated: 2024/03/22 03:06:10 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*new_elem(int fd)
{
	t_gnl	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->fd = fd;
	elem->prev = NULL;
	elem->next = NULL;
	elem->data = NULL;
	return (elem);
}

static t_gnl	*check_list(t_gnl *list, int fd)
{
	t_gnl	*prev;

	if (!list)
		return (NULL);
	while (list)
	{
		if (list->fd == fd)
			return (list);
		prev = list;
		list = list->next;
	}
	list = prev;
	list->next = new_elem(fd);
	list->next->prev = list;
	return (list->next);
}

static char	*get_line(char *buffer, t_gnl *elem, char **line)
{
	char	*tmp;

	if (buffer)
		tmp = ft_strchr(buffer, '\n');
	else if (elem->data)
		tmp = ft_strchr(elem->data, '\n');
	if (elem->data && tmp)
	{
		*tmp = 0;
		*line = ft_strjoin(elem->data, buffer);
		tmp = ft_strjoin(tmp + 1, "");
		if (elem->data)
			free(elem->data);
		elem->data = tmp;
		return (*line);
	}
	if (buffer)
	{
		tmp = elem->data;
		elem->data = ft_strjoin(elem->data, buffer);
		if (tmp)
			free(tmp);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (NULL);
}

static char	*del_elem(t_gnl *elem, char **line)
{
	if (elem->data && *elem->data)
	{
		*line = ft_strjoin(elem->data, "");
		if (elem->data)
			free(elem->data);
		return (*line);
	}
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	if (elem)
		free(elem);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_gnl	*list = NULL;
	t_gnl			*elem;
	int				nb_read;
	char			*line;
	char			*buffer;

	if (!list && fd >= 0)
		list = new_elem(fd);
	elem = check_list(list, fd);
	buffer = malloc(sizeof(BUFFER_SIZE + 1));
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || !list || !elem || read(fd, buffer, 0) < 0)
		return (NULL);
	if (get_line(NULL, elem, &line))
		return (line);
	nb_read = ft_bzero(buffer, BUFFER_SIZE + 1);
	while (nb_read)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (NULL);
		if (get_line(buffer, elem, &line))
			return (line);
	}
	return (del_elem(elem, &line));
}
