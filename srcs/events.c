/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:10:46 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 09:23:14 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotate(t_cub3d *t)
{
	if (t->moves.right == 1 || t->moves.mright == 1)
	{
		t->olddir_x = t->dir_x;
		t->dir_x = t->dir_x * cos(-t->rs) - t->dir_y * sin(-t->rs);
		t->dir_y = t->olddir_x * sin(-t->rs) + t->dir_y * cos(-t->rs);
		t->oldplane_x = t->plane_x;
		t->plane_x = t->plane_x * cos(-t->rs) - t->plane_y * sin(-t->rs);
		t->plane_y = t->oldplane_x * sin(-t->rs) + t->plane_y * cos(-t->rs);
	}
	if (t->moves.left == 1 || t->moves.mleft == 1)
	{
		t->olddir_x = t->dir_x;
		t->dir_x = t->dir_x * cos(t->rs) - t->dir_y * sin(t->rs);
		t->dir_y = t->olddir_x * sin(t->rs) + t->dir_y * cos(t->rs);
		t->oldplane_x = t->plane_x;
		t->plane_x = t->plane_x * cos(t->rs) - t->plane_y * sin(t->rs);
		t->plane_y = t->oldplane_x * sin(t->rs) + t->plane_y * cos(t->rs);
	}
}

void	ft_left_side(t_cub3d *t)
{
	int	x;

	x = 0;
	if (t->moves.rdesp == 1)
	{
		t->tmpdir_x = t->dir_x;
		t->tmpdir_y = t->dir_y;
		while (x++ < 50)
		{
			t->tmpdir = t->dir_x;
			t->dir_x = t->dir_x * cos(-t->rs) - t->dir_y * sin(-t->rs);
			t->dir_y = t->tmpdir * sin(-t->rs) + t->dir_y * cos(-t->rs);
		}
		if (t->map.map[(int)(t->pos_x + t->dir_x * t->ms)][(int)t->pos_y] == '0'
				&& t->map.map[(int)(t->pos_x + t->tmpdir_x * t->ms)]
				[(int)t->pos_y] == '0')
			t->pos_x += t->dir_x * t->ms;
		if (t->map.map[(int)(t->pos_x)]
				[(int)(t->pos_y + t->dir_y * t->ms)] == '0'
				&& t->map.map[(int)(t->pos_x)]
				[(int)(t->pos_y + t->tmpdir_y * t->ms)] == '0')
			t->pos_y += t->dir_y * t->ms;
		t->dir_x = t->tmpdir_x;
		t->dir_y = t->tmpdir_y;
	}
}

void	ft_right_side(t_cub3d *t)
{
	int x;

	x = 0;
	if (t->moves.ldesp == 1)
	{
		t->tmpdir_x = t->dir_x;
		t->tmpdir_y = t->dir_y;
		while (x++ < 50)
		{
			t->tmpdir = t->dir_x;
			t->dir_x = t->dir_x * cos(t->rs) - t->dir_y * sin(t->rs);
			t->dir_y = t->tmpdir * sin(t->rs) + t->dir_y * cos(t->rs);
		}
		if (t->map.map[(int)(t->pos_x + t->dir_x * t->ms)][(int)t->pos_y] == '0'
				&& t->map.map[(int)(t->pos_x + t->tmpdir_x * t->ms)]
				[(int)t->pos_y] == '0')
			t->pos_x += t->dir_x * t->ms;
		if (t->map.map[(int)(t->pos_x)][(int)(t->pos_y + t->dir_y * t->ms)]
				== '0' && t->map.map[(int)(t->pos_x)]
				[(int)(t->pos_y + t->tmpdir_y * t->ms)] == '0')
			t->pos_y += t->dir_y * t->ms;
		t->dir_x = t->tmpdir_x;
		t->dir_y = t->tmpdir_y;
	}
}

int		ft_move(t_cub3d *t)
{
	if (t->moves.up == 1)
	{
		if (t->map.map[(int)(t->pos_x + t->dir_x * t->ms)]
				[(int)(t->pos_y)] == '0')
			t->pos_x += t->dir_x * t->ms;
		if (t->map.map[(int)(t->pos_x)]
				[(int)(t->pos_y + t->dir_y * t->ms)] == '0')
			t->pos_y += t->dir_y * t->ms;
	}
	if (t->moves.down == 1)
	{
		if (t->map.map[(int)(t->pos_x - t->dir_x * t->ms)]
				[(int)(t->pos_y)] == '0')
			t->pos_x -= t->dir_x * t->ms;
		if (t->map.map[(int)(t->pos_x)]
				[(int)(t->pos_y - t->dir_y * t->ms)] == '0')
			t->pos_y -= t->dir_y * t->ms;
	}
	ft_rotate(t);
	ft_left_side(t);
	ft_right_side(t);
	ft_raycasting(t);
	return (0);
}
