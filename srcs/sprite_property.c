/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_property.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:11:18 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 08:17:26 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_tex			ft_get_spr_hg(t_cub3d *t, int count)
{
	t_tex	spr_h;

	t->spr[count].hg = abs((int)(t->map.res_y / t->spr[count].trf_y));
	spr_h.start = -t->spr[count].hg / 2 + t->map.res_y / 2;
	if (spr_h.start < 0)
		spr_h.start = 0;
	spr_h.end = t->spr[count].hg / 2 + t->map.res_y / 2;
	if (spr_h.end >= t->map.res_y)
		spr_h.end = t->map.res_y - 1;
	spr_h.size = t->spr[count].hg;
	return (spr_h);
}

t_tex			ft_get_spr_wd(t_cub3d *t, int count)
{
	t_tex	spr_w;

	t->spr[count].wd = abs((int)(t->map.res_y / t->spr[count].trf_y));
	spr_w.start = -t->spr[count].wd / 2 + t->spr[count].screen_x;
	if (spr_w.start < 0)
		spr_w.start = 0;
	spr_w.end = t->spr[count].wd / 2 + t->spr[count].screen_x;
	if (spr_w.end >= t->map.res_x)
		spr_w.end = t->map.res_x - 1;
	spr_w.size = t->spr[count].wd;
	return (spr_w);
}

unsigned int	ft_get_color(t_cub3d *t, int x, int y)
{
	int	color;

	color = 0;
	ft_memcpy(&color, t->img[4].ptr + x * (t->img[4].bpp / 8) + y
			* t->img[4].szln, t->img[4].bpp / 8);
	return (color);
}

void			ft_put_sprite_pixel(t_cub3d *t, int x, int start, int color)
{
	unsigned int	color_conv;

	color_conv = mlx_get_color_value(t->ptr, color);
	ft_memcpy(t->img[0].ptr + x * (t->img[0].bpp / 8) + start *
			t->img[0].szln, &color_conv, t->img[0].bpp / 8);
}
