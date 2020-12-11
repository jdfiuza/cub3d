/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:40:36 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/27 14:47:55 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, const void *source, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((char*)dest)[i] = ((char*)source)[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (s && (substr = (char*)malloc(sizeof(char) * (len + 1))))
	{
		substr[i] = '\0';
		if (start > ft_strlen(s))
			return (substr);
		s += start;
		while (i < len)
		{
			substr[i] = *s++;
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
