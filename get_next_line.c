/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:58:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/14 10:08:48 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*new_elem(int fd)
{
	t_list	*elem;
	t_gnl	*content;

	if (fd < 0 || !(content = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	content->fd = fd;
	content->data = NULL;
	elem = ft_lstnew(content, 1);
	return (elem);
}

t_list		*check_list(t_list **first, t_list **prev, int fd)
{
	t_list	*elem;
	t_gnl	*content;

	*prev = NULL;
	elem = *first;
	while (elem)
	{
		content = elem->content;
		if (content->fd == fd)
			return (elem);
		*prev = elem;
		elem = elem->next;
	}
	*prev = NULL;
	elem = new_elem(fd);
	ft_lstadd(first, elem);
	return (elem);
}

void		del_elem(t_list **first, int fd)
{
	t_list	*prev;
	t_list	*elem;
	t_gnl	*content;

	elem = check_list(first, &prev, fd);
	content = elem->content;
	ft_bzero(content, sizeof(content));
	free(content);
	if (prev)
		prev->next = elem->next;
	else
		*first = elem->next;
	ft_lstdelone(&elem, ft_bzero);
}

int			check_buffer(char **buffer, char *data, char **line)
{
	char *ptr;
	char *tmp;

	if (ft_strlen(*buffer))
	{
		tmp = (data) ? ft_strjoin(data, *buffer) : ft_strdup(*buffer);
		ft_strdel(&data);
		data = tmp;
	}
	if ((ptr = ft_strchr(data, '\n')))
	{
		*ptr = '\0';
		tmp = (*line) ? ft_strjoin(*line, data) : ft_strdup(data);
		ft_strdel(line);
		*line = tmp;
		tmp = (*(++ptr)) ? ft_strdup(ptr) : NULL;
		ft_strdel(&data);
		data = tmp;
		return (1);
	}
	tmp = (*line) ? ft_strjoin(*line, data) : ft_strdup(data);
	ft_strdel(line);
	ft_strdel(&data);
	*line = tmp;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int				nb_char;
	char			*buffer;
	t_gnl			*content;
	t_list			*prev;
	static t_list	*first = NULL;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || buffer == NULL)
		return (-1);
	if (!first)
		first = new_elem(fd);
	content = check_list(&first, &prev, fd)->content;
	while ((nb_char = read(fd, buffer, BUFF_SIZE)) || content->data)
	{
		if (nb_char < 0)
			return (-1);
		if (check_buffer(&buffer, content->data, line))
		{
			if (!nb_char && !content->data)
				del_elem(&first, fd);
			return (1);
		}
	}
	return (0);
}
