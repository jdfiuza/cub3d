/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:57:40 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/28 08:01:24 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_check_paths(char *text, char *path)
{
	int	fd;

	if ((fd = open(text, O_RDONLY)) < 0)
	{
		free(text);
		text = ft_strdup(path);
	}
	close(fd);
	return (text);
}

static void	ft_load_paths(t_cub3d *t)
{
	t->map.ntext = ft_check_paths(t->map.ntext, "./images/wall_1.xpm");
	t->map.stext = ft_check_paths(t->map.stext, "./images/wall_2.xpm");
	t->map.wtext = ft_check_paths(t->map.wtext, "./images/wall_3.xpm");
	t->map.etext = ft_check_paths(t->map.etext, "./images/wall_4.xpm");
	t->map.sprite = ft_check_paths(t->map.sprite, "./images/sprite_2.xpm");
}

static void	ft_load_walls(t_cub3d *t, int a, int b)
{
	t->img[3].im = mlx_xpm_file_to_image(t->ptr, t->map.ntext, &a, &b);
	t->img[3].ptr = mlx_get_data_addr(t->img[3].im, &t->img[3].bpp,
			&t->img[3].szln, &t->img[3].endian);
	t->img[5].im = mlx_xpm_file_to_image(t->ptr, t->map.stext, &a, &b);
	t->img[5].ptr = mlx_get_data_addr(t->img[5].im, &t->img[5].bpp,
			&t->img[5].szln, &t->img[5].endian);
	t->img[6].im = mlx_xpm_file_to_image(t->ptr, t->map.etext, &a, &b);
	t->img[6].ptr = mlx_get_data_addr(t->img[6].im, &t->img[6].bpp,
			&t->img[6].szln, &t->img[6].endian);
	t->img[7].im = mlx_xpm_file_to_image(t->ptr, t->map.wtext, &a, &b);
	t->img[7].ptr = mlx_get_data_addr(t->img[7].im, &t->img[7].bpp,
			&t->img[7].szln, &t->img[7].endian);
}

void		ft_load_images(t_cub3d *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	ft_load_paths(t);
	ft_load_walls(t, a, b);
	t->img[1].im = mlx_xpm_file_to_image(t->ptr, "images/sky_2.xpm", &a, &b);
	t->img[1].ptr = mlx_get_data_addr(t->img[1].im, &t->img[1].bpp,
			&t->img[1].szln, &t->img[1].endian);
	t->img[2].im = mlx_xpm_file_to_image(t->ptr, "images/sand.xpm", &a, &b);
	t->img[2].ptr = mlx_get_data_addr(t->img[2].im, &t->img[2].bpp,
			&t->img[2].szln, &t->img[2].endian);
	t->img[4].im = mlx_xpm_file_to_image(t->ptr, t->map.sprite, &a, &b);
	t->img[4].ptr = mlx_get_data_addr(t->img[4].im, &t->img[4].bpp,
			&t->img[4].szln, &t->img[4].endian);
}
