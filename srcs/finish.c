/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:19:22 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 08:03:38 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_free_images(t_cub3d *t)
{
	mlx_destroy_image(t->ptr, t->img[1].im);
	mlx_destroy_image(t->ptr, t->img[2].im);
	mlx_destroy_image(t->ptr, t->img[3].im);
	mlx_destroy_image(t->ptr, t->img[4].im);
	mlx_destroy_image(t->ptr, t->img[5].im);
	mlx_destroy_image(t->ptr, t->img[6].im);
	mlx_destroy_image(t->ptr, t->img[7].im);
}

static void	ft_free_config(t_cub3d *t)
{
	free(t->map.resol[0]);
	free(t->map.resol[1]);
	free(t->map.resol[2]);
	free(t->map.floor[0]);
	free(t->map.floor[1]);
	free(t->map.floor[2]);
	free(t->map.ceil[0]);
	free(t->map.ceil[1]);
	free(t->map.ceil[2]);
	free(t->map.ntext);
	free(t->map.stext);
	free(t->map.wtext);
	free(t->map.etext);
	free(t->map.sprite);
}

int			ft_close(t_cub3d *t)
{
	int	i;

	i = 0;
	free(t->dists);
	free(t->spr);
	while (i < t->map.rows)
	{
		free(t->map.map[i]);
		i++;
	}
	free(t->map.map);
	ft_free_images(t);
	ft_free_config(t);
	mlx_destroy_window(t->ptr, t->win);
	exit(1);
	return (0);
}
