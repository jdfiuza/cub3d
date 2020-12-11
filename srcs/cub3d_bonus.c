/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:02:54 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/30 07:52:42 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_cub(t_cub3d *t)
{
	t->ptr = mlx_init();
	t->win = mlx_new_window(t->ptr, t->map.res_x, t->map.res_y, "Cub3D");
}

void	ft_init_basic(t_cub3d *t)
{
	t->map.r = '0';
	t->map.f = '0';
	t->map.c = '0';
	t->points = 0;
	t->levels = (char **)malloc(sizeof(char *) * 2);
	t->levels[0] = ft_strdup("./maps/2.cub");
	t->levels[1] = ft_strdup("./maps/3.cub");
	t->play.life = 100;
}

void	ft_init(t_cub3d *t)
{
	t->pos_x = 10;
	t->pos_y = 6;
	ft_get_pos(t);
	ft_set_player_pos(t);
	t->ms = 0.03;
	t->rs = 0.03;
	t->moves.mright = 0;
	t->moves.up = 0;
	t->moves.down = 0;
	t->moves.left = 0;
	t->moves.right = 0;
	t->text_x = 0;
	t->text_y = 0;
	ft_load_images(t);
	ft_get_sprites(t);
	ft_spr_sort(t);
	t->dists = (double *)malloc(sizeof(double) * t->map.res_x);
	system("Afplay ./sounds/doom.mp3&");
}
