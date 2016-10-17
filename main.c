/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:13:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/17 04:33:54 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int		i;
	//int		j;
	int		fd1;
	//int		fd2;
	char	*line;

	i		= 1;
	//j		= 1;
	line	= NULL;
	fd1		= open("test", O_RDONLY);
	//fd2		= open("test1", O_RDONLY);
	//while (i || j)
	while ((i = get_next_line(fd1, &line)))
	{
		//i = get_next_line(fd1, &line);
		printf("1: %i: %s\n", i, line);
		ft_strdel(&line);
		//j = get_next_line(fd2, &line);
		//printf("2: %i: %s\n", j, line);
		//ft_strdel(&line);
	}
	printf("%i: END\n", i);
	//printf("%i: END\n", j);
	return (0);
}
