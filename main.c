/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:13:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/14 09:58:47 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int		i;
	int		j;
	int		fd1;
	int		fd2;
	char	*line;

	i		= 1;
	j		= 1;
	line	= NULL;
	fd1		= open("test", O_RDONLY);
	fd2		= open("test1", O_RDONLY);
	while (i || j)
	{
		i = get_next_line(fd1, &line);
		printf("1: %i: %s\n", i, line);
		ft_strdel(&line);
		j = get_next_line(fd2, &line);
		printf("2: %i: %s\n", j, line);
		ft_strdel(&line);
	}
	printf("END\n%d\n", i);
	printf("END\n%d\n", j);
	return (0);
}
