/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:13:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/10 03:15:11 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int		i;
	int		fd;
	char	*line;

	line	= NULL;
	fd		= open("test", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%i: %s\n", i, line);
		ft_strdel(&line);
	}
	printf("END\n%d\n", i);
	return (0);
}
