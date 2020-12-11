/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:18:18 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/15 12:35:15 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
