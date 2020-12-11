/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:17:28 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 08:32:27 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_wall(t_cub3d *t)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (i < t->map.rows)
	{
		if (t->map.map[i][0] != '1' || t->map.map[i][t->map.cols - 2] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < t->map.cols - 1)
	{
		if (t->map.map[0][i] != '1' || t->map.map[t->map.rows - 1][i] != '1')
			return (1);
		i++;
	}
	return (ret);
}

static int	ft_check_player(t_cub3d *t)
{
	int		ret;
	int		cont_pos;
	int		i;
	int		j;
	char	c;

	ret = 0;
	cont_pos = 0;
	i = -1;
	while (++i < t->map.rows)
	{
		j = -1;
		while (++j < t->map.cols)
		{
			c = (char)t->map.map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				cont_pos++;
				t->map.map[i][j] = '0';
			}
		}
	}
	if (cont_pos != 1)
		ret = 1;
	return (ret);
}

static int	ft_check_content(t_cub3d *t)
{
	int		ret;
	int		i;
	int		j;
	char	c;

	ret = 0;
	i = -1;
	if (t->map.rows < 6 || t->map.cols < 7)
		return (1);
	while (++i < t->map.rows)
	{
		j = -1;
		while (++j < t->map.cols)
		{
			c = (char)t->map.map[i][j];
			if (((c < '0' || c > '2') && (c != '\0')))
				ret = 1;
		}
	}
	return (ret);
}

int			ft_validate_map(t_cub3d *t)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (i < t->map.rows)
	{
		if (ft_strlen(t->map.map[i]) != (size_t)(t->map.cols - 1))
			return (1);
		i++;
	}
	if ((ret = ft_check_wall(t)))
		return (ret);
	if ((ret = ft_check_player(t)))
		return (ret);
	if ((ret = ft_check_content(t)))
		return (ret);
	return (ret);
}
