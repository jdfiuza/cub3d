/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:54:55 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 07:42:17 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (t->saved_img == 0)
		ft_save_img(t);
	mlx_put_image_to_window(t->ptr, t->win, t->img[0].im, 0, 0);
	mlx_destroy_image(t->ptr, t->img[0].im);
}
