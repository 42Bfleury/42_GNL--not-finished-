/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:59:20 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/17 04:20:11 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3

#include <stdio.h>
# include "../Libft/libft.h"

typedef struct				s_gnl
{
	int						fd;
	char					*data;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif
