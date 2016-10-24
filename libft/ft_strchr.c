/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <benjamin.fleury@hotmail.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:40:41 by bfleury           #+#    #+#             */
/*   Updated: 2016/10/24 04:43:21 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while ((char)*str)
	{
		if ((char)*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)*str == (char)c)
		return ((char *)str);
	return (NULL);
}
