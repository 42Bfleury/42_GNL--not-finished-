/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:54:55 by bfleury           #+#    #+#             */
/*   Updated: 2024/03/03 03:43:07 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*new_element(int fd)
{
	t_gnl	*element;

	if (fd < 0)
		return (NULL);
	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->fd = fd;
	element->line = "";
	element->next = NULL;
	return (element);
}

static t_gnl	*get_element(t_gnl *lst, int fd)
{
	t_gnl	*last;

	if (!lst || fd < 0)
		return (NULL);
	while (lst)
	{
		last = lst;
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	last->next = new_element(fd);
	return (last->next);
}

static char	*get_line(t_gnl *element)
{
	return ("");
}

char	*get_next_line(int fd)
{
	static t_gnl	*lst = NULL;
	t_gnl			*element;
	char			*result;

	if (fd < 0)
		return (NULL);
	if (!lst)
		lst = new_elem(fd);
	element = get_element(lst, fd);
	result = get_line(element);
	return (result);
}

	/*char			buffer[BUFFER_SIZE];
	int				nb_read;

	result = malloc((sizeof(*result) * BUFFER_SIZE) + 2);
	if (!result || fd < 0)
	{
		if (result)
			free(result);
		if (DEBBUG)
			printf("%s {get_next_line} - malloc(result) failed...\n", RERROR);
		return (NULL);
	}
	nb_read = read(fd, result, BUFFER_SIZE);
	if (nb_read <= 0 || fd < 0)
	{
		if (result)
			free(result);
		if (!nb_read && DEBBUG)
			printf("%s Nothing to read from [fd: %i]\n", YINFO, fd);
		else if (DEBBUG)
			printf("%s Failed to read from [fd: %i]...\n", RERROR, fd);
		return (NULL);
	}
	else if (DEBBUG)
		printf("%s Read %i char from [fd: %i]\n", GINFO, nb_read, fd);
	result[nb_read] = '\n';
	result[nb_read + 1] = 0;
	return (result);*/