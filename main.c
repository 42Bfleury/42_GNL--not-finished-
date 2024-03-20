/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:40:54 by bfleury           #+#    #+#             */
/*   Updated: 2024/03/05 22:19:54 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		if (DEBBUG)
			printf("%s Couldn't open file \"%s\"...\n", RERROR, filename);
		return (-1);
	}
	if (DEBBUG)
		printf("%s Open file \"%s\" with [fd: %i]\n", GINFO, filename, fd);
	return (fd);
}

int	print_next_line(int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
	{
		if (DEBBUG)
			printf("%s Nothing to print from [fd: %i]\n", YINFO, fd);
		return (0);
	}
	printf("\e[1;34m[fd: %i]:\e[0m %s", fd, str);
	return (1);
}

int	main(void)
{
	int		fd[4];
	char	*filename[4];

	filename[0] = "test0.txt";
	filename[1] = "test1.txt";
	filename[2] = "test2.txt";
	filename[3] = "test3.txt";
	fd[0] = open_file(filename[0]);
	fd[1] = open_file(filename[1]);
	fd[2] = open_file(filename[2]);
	fd[3] = open_file(filename[3]);
	fd[4] = open_file(filename[4]);
	print_next_line(fd[0]);
	print_next_line(fd[1]);
	print_next_line(fd[2]);
	print_next_line(fd[3]);
	print_next_line(fd[4]);
	print_next_line(fd[0]);
	return (0);
}*/

int	main(void)
{
	int		i = 0;
	int		fd;
	char	*line;

	line = "test0.txt";
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		if (DEBBUG)
			printf("%s Couldn't open file \"%s\"...\n", RERROR, line);
		return (-1);
	}
	if (DEBBUG)
		printf("%s Open file \"%s\" with [fd: %i]\n", GINFO, line, fd);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("\e[1;34m[fd: %i]:\e[0m %s", fd, line);
			free(line);
		}
	}
	return (0);
}
