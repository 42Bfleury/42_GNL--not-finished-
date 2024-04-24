/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:56:57 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/21 21:37:09 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	c %= 256;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strdup(char *str, int len)
{
	int		i;
	char	*result;

	if (!str || !len)
		return (NULL);
	i = 0;
	result = malloc(sizeof(*result) * (len + 1));
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(str1) + ft_strlen(str2);
	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	len = 0;
	if (str1)
		while (str1[i])
			result[len++] = str1[i++];
	i = 0;
	if (str2)
		while (str2[i])
			result[len++] = str2[i++];
	result[len] = 0;
	free(str1);
	return (result);
}

/*	char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*str;

	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	len += ft_strlen(s1);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	free(s1);
	return (str);
}*/
