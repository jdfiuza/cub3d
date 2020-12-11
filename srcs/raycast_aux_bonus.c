/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:54:55 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 07:45:58 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_look(t_cub3d *t)
{
	if (t->moves.look_up == 1)
	{
		t->start += 100;
		t->end += 100;
	}
	if (t->moves.look_down == 1)
	{
		t->start -= 100;
		t->end -= 100;
	}
}

void	ft_animation(t_cub3d *t)
{
	int			a;
	int			b;

	a = 64;
	b = 64;
	if (t->map_x % 2 == 0 && t->map_y % 2 == 0)
		t->img[4].im = mlx_xpm_file_to_image(t->ptr, t->map.sprite, &a, &b);
	else
		t->img[4].im = mlx_xpm_file_to_image(t->ptr, t->map.sprite2, &a, &b);
}

void	ft_aux_raycasting(t_cub3d *t)
{
	t->img[0].im = mlx_new_image(t->ptr, t->map.res_x, t->map.res_y);
	t->img[0].ptr = mlx_get_data_addr(t->img[0].im, &t->img[0].bpp,
			&t->img[0].szln, &t->img[0].endian);
	if (t->flagtex == 0)
	{
		ft_put_ceilin(t);
		ft_put_floor(t);
	}
}

void	ft_put_image(t_cub3d *t)
{
	char *life;

	ft_lose_life(t);
	life = ft_itoa(t->play.life);
	if (t->saved_img == 0)
		ft_save_img(t);
	mlx_put_image_to_window(t->ptr, t->win, t->img[0].im, 0, 0);
	mlx_put_image_to_window(t->ptr, t->win, t->img[8].im, 50, 20);
	mlx_put_image_to_window(t->ptr, t->win, t->img[9].im, t->map.res_x
			/ 2 - 256, t->map.res_y - 182);
	mlx_put_image_to_window(t->ptr, t->win, t->img[10].im,
			t->map.res_x * 0.22, t->map.res_y - 75);
	mlx_string_put(t->ptr, t->win, t->map.res_x * 0.32,
			t->map.res_y - 55, 223, life);
	mlx_destroy_image(t->ptr, t->img[0].im);
	free(life);
}
