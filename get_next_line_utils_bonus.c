/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:08:57 by bfleury           #+#    #+#             */
/*   Updated: 2024/04/27 02:40:56 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	if (!str)
		return (0);
	int (i) = 0;
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

char	*ft_gnl_strdup(char *str, int len)
{
	if (!str || !len)
		return (NULL);
	int (i) = 0;
	char *(result) = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_gnl_strjoin(char *str1, char *str2)
{
	int (len) = ft_strlen(str1) + ft_strlen(str2);
	char *(result) = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (free(str1), str1 = NULL, NULL);
	int (i) = 0;
	len = 0;
	if (str1)
		while (str1[i])
			result[len++] = str1[i++];
	i = 0;
	if (str2)
		while (str2[i])
			result[len++] = str2[i++];
	result[len] = 0;
	return (free(str1), str1 = NULL, result);
}
