/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:06:04 by bfleury           #+#    #+#             */
/*   Updated: 2024/04/21 21:40:07 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

//		get_next_line_bonus.c		//
char	*get_next_line(int fd);
char	*print_line(char **tempo);

//		get_next_line_utils_bonus.c		//
int		ft_strlen(char *str);
char	*ft_strdup(char *s, int len);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *str, char c);

#endif