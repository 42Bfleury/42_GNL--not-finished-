/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:13:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/20 16:50:26 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		i;
	int		j;
	int		fd1;
	int		fd2;
	char	*line;

	j		= 1;
	line	= NULL;
	fd1		= open("test", O_RDONLY);
	fd2		= open("test1", O_RDONLY);
	while ((j%2 && (i = get_next_line(fd1, &line)))
			|| (i = get_next_line(fd2, &line)))
	//while ((i = get_next_line(fd1, &line)))
	{
		if (j%2)
			printf("1");
		else
			printf("2");
		printf(": %i: %s\n", i, line);
		j++;
		ft_strdel(&line);
	}
	printf("%i: END\n", i);
	return (0);
}
