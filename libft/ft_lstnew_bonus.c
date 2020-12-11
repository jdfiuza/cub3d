/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:24:39 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/19 08:41:28 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *s1)
{
	size_t	i;

	i = 0;
	while (*s1++)
		i++;
	return (i);
}

t_list			*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (content == NULL)
		list->content = NULL;
	else
	{
		if (!(list->content = malloc(ft_len(content) + 1)))
		{
			free(list);
			return (NULL);
		}
		list->content = content;
	}
	list->next = NULL;
	return (list);
}
