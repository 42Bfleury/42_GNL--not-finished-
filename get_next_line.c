/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:58:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/20 19:34:37 by bfleury          ###   ########.fr       */
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

void		del_elem(t_gnl **elem)
{
	if ((*elem)->prev)
		(*elem)->prev->next = (*elem)->next;
	if ((*elem)->next)
		(*elem)->next->prev = (*elem)->prev;
	free(*elem);
	*elem = NULL;
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

int			check_buffer_data(char **buffer, t_gnl **elem, char **line)
{
	char	*tmp;

	if (ft_strlen(*buffer))
	{
		if ((*elem)->data)
			tmp = ft_strjoin((*elem)->data, *buffer);
		else
			tmp = ft_strdup(*buffer);
		ft_strdel(&(*elem)->data);
		(*elem)->data = tmp;
		ft_bzero(*buffer, BUFF_SIZE);
	}
	ft_bzero(*buffer, BUFF_SIZE);
	if ((*elem)->data && (tmp = ft_strchr((*elem)->data, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup((*elem)->data);
		tmp = (*(tmp + 1)) ? ft_strdup(tmp + 1) : NULL;
		ft_strdel(&(*elem)->data);
		(*elem)->data = tmp;
		ft_strdel(buffer);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*first = NULL;
	t_gnl			*elem;
	char			*buffer;
	int				nb_char;

	first = (first) ? first : new_elem(fd);
	if (fd < 0 || !line || !first)
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	elem = check_lst(&first, fd);
	while ((nb_char = read(fd, buffer, BUFF_SIZE)) || elem->data)
	{
		if (nb_char < 0)
		{
			ft_strdel(&buffer);
			return (-1);
		}
		if (check_buffer_data(&buffer, &elem, line))
			return (1);
	}
	ft_strdel(&buffer);
	del_elem(&elem);
	return (0);
}
