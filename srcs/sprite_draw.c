/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:01:17 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 08:17:46 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_draw_texture_h(t_cub3d *t, int x, int tex_x, t_tex hg)
{
	int	tex_y;
	int color;
	int	stripe;
	int d;

	stripe = hg.start;
	while (stripe < hg.end)
	{
		d = stripe * 256 - t->map.res_y * 128 + hg.size * 128;
		tex_y = ((d * 64) / hg.size) / 256;
		color = ft_get_color(t, tex_x, tex_y);
		if (color != 0)
			ft_put_sprite_pixel(t, x, stripe, color);
		stripe++;
	}
}

void			ft_draw_sprite(t_cub3d *t, int count)
{
	t_tex			width;
	t_tex			height;
	int				tex_x;

	t->spr[count].screen_x = (int)((t->map.res_x / 2) * (1 + t->spr[count].trf_x
				/ t->spr[count].trf_y));
	height = ft_get_spr_hg(t, count);
	width = ft_get_spr_wd(t, count);
	while (width.start < width.end)
	{
		tex_x = (int)(256 * (width.start - (-width.size / 2
				+ t->spr[count].screen_x)) * t->spr[count].width
				/ width.size) / 256;
		if (t->spr[count].trf_y > 0 && width.start > 0
				&& width.start < t->map.res_x
				&& t->spr[count].trf_y < t->dists[width.start])
			ft_draw_texture_h(t, width.start, tex_x, height);
		width.start++;
	}
}

void			ft_get_transform(t_cub3d *t, int count)
{
	t->inv_det = 1.0 / (t->plane_x * t->dir_y - t->dir_x * t->plane_y);
	t->spr[count].trf_x = t->inv_det * (t->dir_y * t->spr[count].spr_x
			- t->dir_x * t->spr[count].spr_y);
	t->spr[count].trf_y = t->inv_det * (-t->plane_y * t->spr[count].spr_x
			+ t->plane_x * t->spr[count].spr_y);
}

void			ft_draw_sprites(t_cub3d *t)
{
	int	i;

	i = 0;
	while (i < t->count_spr)
	{
		t->spr[i].spr_x = t->spr[i].x - t->pos_x;
		t->spr[i].spr_y = t->spr[i].y - t->pos_y;
		t->spr[i].width = 64;
		t->spr[i].height = 64;
		t->spr[i].dist = ft_get_spr_dist(t, i);
		ft_spr_sort(t);
		ft_get_transform(t, i);
		mlx_destroy_image(t->ptr, t->img[4].im);
		if (t->spr[i].id == 0)
			t->img[4].im = mlx_xpm_file_to_image(t->ptr, t->map.sprite,
					&t->spr[i].width, &t->spr[i].height);
		else
			t->img[4].im = mlx_xpm_file_to_image(t->ptr,
					"./images/sprite_1.xpm",
					&t->spr[i].width, &t->spr[i].height);
		t->img[4].ptr = mlx_get_data_addr(t->img[4].im, &t->img[4].bpp,
				&t->img[4].szln, &t->img[4].endian);
		ft_draw_sprite(t, i);
		i++;
	}
}
