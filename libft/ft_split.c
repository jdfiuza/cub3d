/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:05:38 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/18 14:56:59 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		ft_countwords(char *str, char sep)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		result++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (result);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		cleanup(char **split, size_t cur)
{
	size_t	i;

	i = 0;
	while (i < cur)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	cur;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_countwords((char *)s, c);
	split = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	cur = 0;
	while (cur < wordcount)
	{
		s = next_word(s, c);
		split[cur] = ft_substr(s, 0, word_len(s, c));
		if (split[cur] == NULL)
		{
			cleanup(split, cur);
			return (NULL);
		}
		cur++;
		s += word_len(s, c);
	}
	split[wordcount] = NULL;
	return (split);
}
