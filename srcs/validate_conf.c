/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:04:45 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 08:16:37 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_is_valid_num(t_cub3d *t, char *n1, char *n2)
{
	int width;
	int	height;

	width = ft_atoi(n1);
	height = ft_atoi(n2);
	if (width < MIN_WIDTH || height < MIN_WIDTH)
	{
		t->map.res_x = MIN_WIDTH;
		t->map.res_y = MIN_HEIGHT;
	}
	else if (width > MAX_WIDTH || height > MAX_HEIGHT)
	{
		t->map.res_x = MAX_WIDTH;
		t->map.res_y = MAX_HEIGHT;
	}
}

static int	ft_is_valid_color(char *c1, char *c2, char *c3)
{
	int	r;
	int g;
	int b;
	int ret;

	ret = 0;
	r = ft_atoi(c1);
	g = ft_atoi(c2);
	b = ft_atoi(c3);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ret = 1;
	return (ret);
}

int			ft_check_resol(t_cub3d *t)
{
	int ret;

	ret = 0;
	if (t->map.r != 'R')
		ret = 1;
	else if (ft_strcmp(t->map.resol[0], "R") != 0)
		ret = 1;
	else
	{
		if (ft_isnum(t->map.resol[1]) == 0 && ft_isnum(t->map.resol[2]) == 0)
			ft_is_valid_num(t, t->map.resol[1], t->map.resol[2]);
		else
			ret = 1;
	}
	return (ret);
}

int			ft_check_floor_color(t_cub3d *t)
{
	int ret;

	ret = 0;
	if (t->map.f != 'F')
		ret = 1;
	else
	{
		if (ft_isnum(t->map.floor[0]) == 0 && ft_isnum(t->map.floor[1]) == 0
				&& ft_isnum(t->map.floor[2]) == 0)
			ret = ft_is_valid_color(t->map.floor[0], t->map.floor[1],
					t->map.floor[2]);
		else
			ret = 1;
	}
	return (ret);
}

int			ft_check_ceilin_color(t_cub3d *t)
{
	int ret;

	ret = 0;
	if (t->map.c != 'C')
		ret = 1;
	else
	{
		if (ft_isnum(t->map.ceil[0]) == 0 && ft_isnum(t->map.ceil[1]) == 0
				&& ft_isnum(t->map.ceil[2]) == 0)
			ret = ft_is_valid_color(t->map.ceil[0], t->map.ceil[1],
					t->map.ceil[2]);
		else
			ret = 1;
	}
	return (ret);
}
