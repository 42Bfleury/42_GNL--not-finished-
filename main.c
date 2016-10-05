/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:13:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/05 09:46:32 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;

	line = ft_strnew(0);
	fd = open("test", O_RDONLY);
	if (fd < 0)
	{
		printf("Error.\n");
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
		printf("%s\n\n", line);
	printf("\n");
	return (0);
}
