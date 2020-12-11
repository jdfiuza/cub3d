/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:58:56 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/15 12:28:17 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	const char	*p2;

	if (dst == NULL && src == NULL)
		return (0);
	p1 = dst;
	p2 = (const char *)src;
	while (n--)
		*p1++ = *p2++;
	return (dst);
}
