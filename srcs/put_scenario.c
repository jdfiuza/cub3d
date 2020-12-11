/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_scenario.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:34:19 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 08:22:21 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pxl_to_img(t_cub3d *t, int x, int y)
{
	if (x < t->map.res_x && y < t->map.res_y)
	{
		t->text_y = abs((((y * 256 - t->map.res_y * 128 + t->lineheight * 128)
					* 64) / t->lineheight) / 256);
		if (t->side == 1)
		{
			ft_memcpy(t->img[0].ptr + 4 * t->map.res_x * y + x * 4,
				&t->img[t->id + 4].ptr[t->text_y % 64 * t->img[t->id + 4].szln +
				t->text_x % 64 * t->img[t->id + 4].bpp / 8], sizeof(int));
		}
		else
		{
			ft_memcpy(t->img[0].ptr + 4 * t->map.res_x * y + x * 4,
				&t->img[t->id + 2].ptr[t->text_y % 64 * t->img[t->id + 2].szln +
				t->text_x % 64 * t->img[t->id + 2].bpp / 8], sizeof(int));
		}
	}
}

void	ft_floor_ceilin(t_cub3d *t, int x)
{
	if (t->start > 0)
	{
		t->y = -1;
		if (x < t->map.res_x && t->y < t->map.res_y)
			while (++t->y < t->start)
			{
				ft_memcpy(t->img[0].ptr + 4 * t->map.res_x * t->y + x * 4,
					&t->map.c_color, sizeof(int));
			}
	}
	if (t->end > 0)
	{
		t->y = t->end - 1;
		if (x < t->map.res_x && t->y < t->map.res_y)
			while (++t->y < t->map.res_y)
				ft_memcpy(t->img[0].ptr + 4 * t->map.res_x * t->y + x * 4,
						&t->map.f_color, sizeof(int));
	}
}

void	ft_put_ceilin(t_cub3d *t)
{
	int i;
	int j;
	int tmp;
	int calc;

	i = 0;
	while (i < t->map.res_x)
	{
		j = 0;
		while (j < t->map.res_y / 2)
		{
			calc = 4 * t->map.res_x * j + i * 4;
			tmp = j % t->map.res_x * t->img[1].szln + i % t->map.res_x
				* t->img[1].bpp / 8;
			ft_memcpy(t->img[0].ptr + calc, &t->img[1].ptr[tmp], sizeof(int));
			j++;
		}
		i++;
	}
}

void	ft_put_floor(t_cub3d *t)
{
	int i;
	int j;
	int tmp;
	int calc;

	i = 0;
	while (i < t->map.res_x)
	{
		j = t->map.res_y / 2;
		while (j < t->map.res_y)
		{
			calc = 4 * t->map.res_x * j + i * 4;
			tmp = j % 64 * t->img[2].szln + i % 64 * t->img[2].bpp / 8;
			ft_memcpy(t->img[0].ptr + calc, &t->img[2].ptr[tmp], sizeof(int));
			j++;
		}
		i++;
	}
}

void	ft_put_wall(int x, int start, int end, t_cub3d *t)
{
	t->id = (int)t->map.map[t->map_x][t->map_y] - 48;
	if (t->map.map[t->map_x][t->map_y] == '2')
		t->map.map[t->map_x][t->map_y] = '0';
	if (t->side == 0)
		t->wall_x = t->pos_y + t->walldist * t->raydir_y;
	else
		t->wall_x = t->pos_x + t->walldist * t->raydir_x;
	t->text_x = (int)(t->wall_x * (double)(64));
	if (t->side == 0 && t->raydir_x > 0)
		t->text_x = 64 - t->text_x - 1;
	if (t->side == 1 && t->raydir_y < 0)
		t->text_x = 64 - t->text_x - 1;
	t->text_x = abs(t->text_x);
	if (t->id == 1)
	{
		while (++start <= end)
			put_pxl_to_img(t, x, start);
	}
}
