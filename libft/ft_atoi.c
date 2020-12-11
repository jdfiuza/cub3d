/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 07:37:26 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/18 13:12:53 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_l(void)
{
	size_t	lmts;

	lmts = (size_t)(9223372036854775807 / 10);
	return (lmts);
}

int				ft_atoi(const char *s)
{
	int				sign;
	unsigned long	r;

	r = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		if ((r > ft_l() || (r == ft_l() && (*s - '0') > 7)) && sign == 1)
			return (-1);
		else if ((r > ft_l() || (r == ft_l() && (*s - '0') > 8)) && sign == -1)
			return (0);
		r = r * 10 + *s - '0';
		s++;
	}
	return (sign * (int)r);
}
