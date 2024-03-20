/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:11:29 by bfleury           #+#    #+#             */
/*   Updated: 2024/03/07 19:14:12 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	512
# endif
# include <stdlib.h>
# include <unistd.h>
# ifndef DEBBUG
#  define DEBBUG 1
#  define RERROR "\e[1;4;7;31mERROR:\e[0m"
#  define GINFO "\e[1;7;32mINFO:\e[0m"
#  define YINFO "\e[1;7;33mINFO:\e[0m"
# endif
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gnl
{
	int						fd;
	char					*line;
	struct s_gnl			*next;
}							t_gnl;

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
