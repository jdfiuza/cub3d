/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpm_to_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:55:33 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/28 07:19:40 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/img.h"
#include "../includes/cub3d.h"

static void	ft_set_file_header(t_cub3d *t, t_image *i)
{
	u_int32_t	sz;

	sz = t->map.res_x * t->map.res_y * (t->img[0].bpp / 8) + 54;
	ft_memcpy(&i->fh.bf_type, "\x42\x4D", 2);
	i->fh.bf_size = sz;
	i->fh.bf_reserved1 = 0;
	i->fh.bf_reserved2 = 0;
	i->fh.bf_offbits = 54;
}

static void	ft_set_info_header(t_cub3d *t, t_image *i)
{
	i->fi.bi_size = 40;
	i->fi.bi_width = t->map.res_x;
	i->fi.bi_height = -t->map.res_y;
	i->fi.bi_planes = 1;
	i->fi.bi_bit_count = t->img[0].bpp;
	i->fi.bi_compression = 0;
	i->fi.bi_img_size = 0;
	i->fi.bi_x_ppm = 0;
	i->fi.bi_y_ppm = 0;
	i->fi.bi_clr_used = 0;
	i->fi.bi_clr_important = 0;
}

static void	ft_write_header(t_image *i, int fd)
{
	write(fd, &i->fh.bf_type, 2);
	write(fd, &i->fh.bf_size, 4);
	write(fd, &i->fh.bf_reserved1, 2);
	write(fd, &i->fh.bf_reserved2, 2);
	write(fd, &i->fh.bf_offbits, 4);
}

static void	ft_write_info(t_image *i, int fd)
{
	write(fd, &i->fi.bi_size, 4);
	write(fd, &i->fi.bi_width, 4);
	write(fd, &i->fi.bi_height, 4);
	write(fd, &i->fi.bi_planes, 2);
	write(fd, &i->fi.bi_bit_count, 2);
	write(fd, &i->fi.bi_compression, 4);
	write(fd, &i->fi.bi_img_size, 4);
	write(fd, &i->fi.bi_x_ppm, 4);
	write(fd, &i->fi.bi_y_ppm, 4);
	write(fd, &i->fi.bi_clr_used, 4);
	write(fd, &i->fi.bi_clr_important, 4);
}

void		ft_save_img(t_cub3d *t)
{
	int		fd;
	t_image	image;

	fd = open("./saved_image/saved.bmp", O_WRONLY | O_CREAT, S_IRWXU
		| S_IROTH | S_IRGRP);
	ft_set_file_header(t, &image);
	ft_set_info_header(t, &image);
	ft_write_header(&image, fd);
	ft_write_info(&image, fd);
	image.ct.rgb_blue = (uint8_t *)mlx_get_data_addr(t->img[0].im,
			&t->img[0].bpp, &t->img[0].szln, &t->img[0].endian);
	write(fd, image.ct.rgb_blue, t->map.res_x * t->map.res_y
			* (t->img[0].bpp / 8));
	t->saved_img = 1;
	close(fd);
}
