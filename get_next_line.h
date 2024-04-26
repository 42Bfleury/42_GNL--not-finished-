/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:06:04 by bfleury           #+#    #+#             */
/*   Updated: 2024/04/26 16:22:38 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

//		get_next_line.c		//
char	*get_next_line(int fd);
// char	*_get_line(char **str);

//		get_next_line_utils.c		//
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *str1, char *str2);

#endif