/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:03:30 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/30 14:51:36 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_dda(t_cub3d *t)
{
	t->deltadist_x = fabs(1.0 / t->raydir_x);
	t->deltadist_y = fabs(1.0 / t->raydir_y);
	if (t->raydir_x < 0)
	{
		t->step_x = -1;
		t->sidedist_x = (t->pos_x - t->map_x) * t->deltadist_x;
	}
	else
	{
		t->step_x = 1;
		t->sidedist_x = (t->map_x + 1.0 - t->pos_x) * t->deltadist_x;
	}
	if (t->raydir_y < 0)
	{
		t->step_y = -1;
		t->sidedist_y = (t->pos_y - t->map_y) * t->deltadist_y;
	}
	else
	{
		t->step_y = 1;
		t->sidedist_y = (t->map_y + 1.0 - t->pos_y) * t->deltadist_y;
	}
}

void	ft_dda(t_cub3d *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->sidedist_x < t->sidedist_y)
		{
			t->sidedist_x += t->deltadist_x;
			t->map_x += t->step_x;
			t->side = 0;
		}
		else
		{
			t->sidedist_y += t->deltadist_y;
			t->map_y += t->step_y;
			t->side = 1;
		}
		if (t->map.map[t->map_x][t->map_y] > '0')
			t->hit = 1;
	}
}

void	ft_init_raycasting(t_cub3d *t, int x)
{
	t->cam_x = 2 * x / (double)(t->map.res_x) - 1;
	t->raypos_x = t->pos_x;
	t->raypos_y = t->pos_y;
	t->raydir_x = t->dir_x + t->plane_x * t->cam_x;
	t->raydir_y = t->dir_y + t->plane_y * t->cam_x;
	t->map_x = (int)t->raypos_x;
	t->map_y = (int)t->raypos_y;
	ft_init_dda(t);
	ft_dda(t);
	if (t->side == 0)
		t->walldist = (t->map_x - t->pos_x +
				(1.0 - t->step_x) / 2.0) / t->raydir_x;
	else
		t->walldist = (t->map_y - t->pos_y +
				(1.0 - t->step_y) / 2.0) / t->raydir_y;
}

void	ft_raycasting(t_cub3d *t)
{
	t->x = -1;
	ft_aux_raycasting(t);
	while (++t->x < t->map.res_x)
	{
		ft_init_raycasting(t, t->x);
		t->lineheight = (int)(t->map.res_y / t->walldist);
		t->start = -t->lineheight / 2 + t->map.res_y / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineheight / 2 + t->map.res_y / 2;
		if (t->end >= t->map.res_y)
			t->end = t->map.res_y - 1;
		ft_look(t);
		if (t->side == 1)
			t->color = 0x79DBB8;
		else
			t->color = 0xE1E87D;
		if (t->flagtex == 1)
			ft_floor_ceilin(t, t->x);
		ft_put_wall(t->x, t->start, t->end, t);
		t->dists[t->x] = t->walldist;
	}
	ft_draw_sprites(t);
	ft_put_image(t);
	ft_earn_points(t);
}
