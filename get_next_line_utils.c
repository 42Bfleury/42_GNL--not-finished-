/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:17:05 by bfleury           #+#    #+#             */
/*   Updated: 2024/03/22 02:56:31 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n)
	{
		tmp[n - 1] = 0;
		n--;
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptrdest;
	char	*ptrsrc;

	if (n && dest != src)
	{
		ptrdest = (char *)dest;
		ptrsrc = (char *)src;
		while (n)
		{
			*ptrdest = *ptrsrc;
			ptrdest++;
			ptrsrc++;
			n--;
		}
	}
	return (dest);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	lenght;
	char	*result;

	if (!str)
		return (NULL);
	lenght = 0;
	while (str[lenght])
		lenght++;
	if (start > lenght)
		len = 0;
	else if (start + len > lenght)
		len = lenght - start;
	result = malloc(sizeof(*result) * len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, &str[start], len);
	result[len] = 0;
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	result = malloc(sizeof(*result) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(&result[len1], s2, len2);
	result[len1 + len2] = 0;
	return (result);
}
