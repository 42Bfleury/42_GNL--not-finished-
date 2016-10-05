/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:59:20 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/05 09:39:08 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3

#include <stdio.h>
# include "../Libft/libft.h"

typedef struct				s_double_list
{
	int						fd;
	void					*content;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}							t_double_list;

int							get_next_line(const int fd, char **line);

#endif
