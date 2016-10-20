/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:13:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/20 19:41:24 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		i;
	int		fd1;
	char	*line;
	int		j;
	int		fd2;
	//char	tmp[3];

	line	= NULL;
	fd1		= open("test1", O_RDONLY);
	fd2		= open("test", O_RDONLY);
	j		= 1;
	while ((j%2 && (i = get_next_line(fd1, &line)))
			|| ((i = get_next_line(fd2, &line)) && (j = 2))
			|| ((i = get_next_line(fd1, &line) && (j = 1))))
	{
		if (j%2)
			printf("1");
		else
			printf("2");
		printf(": %i: %s\n", i, line);
		j++;
		ft_strdel(&line);
	}
	printf("END\n");
	/*while ((i = get_next_line(fd1, &line)))
	{
		if (i < 0)
			line = "Error.";
		printf("%i: %s\n", i, line);
		ft_strdel(&line);
		i = (i < 0) ? 0 : i;
	}
	printf("END\n");
	while ((i = read(fd1, tmp, 2)))
	{
		write(1, "[", 1);
		if (tmp[0] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &tmp[0], 1);
		write(1, ",", 1);
		if (tmp[1] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &tmp[1], 1);
		write(1, ",", 1);
		if (tmp[2] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &tmp[2], 1);
		write(1, "]", 1);
		write(1, "\n", 1);
		ft_bzero(tmp, 3);
	}
	printf("END\n");*/
	return (0);
}
