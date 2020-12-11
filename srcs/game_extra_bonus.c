/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_extra_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:34:17 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 08:46:46 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_secret(t_cub3d *t)
{
	if ((int)t->pos_x == 5 && (int)t->pos_y == 17)
	{
		t->map.map[5][18] = '0';
		t->map.mapaux[9][15] = '2';
		ft_get_sprites(t);
		ft_spr_sort(t);
	}
}

void	ft_earn_points(t_cub3d *t)
{
	char	*point;

	point = ft_itoa(t->points);
	mlx_string_put(t->ptr, t->win, t->map.res_x * 0.27,
			t->map.res_y - 55, 223, point);
	free(point);
}

void	ft_door(t_cub3d *t)
{
	static int i = 0;

	if (16 == (int)t->pos_x && 9 == (int)t->pos_y
			&& i == 0)
	{
		t->map.map[t->play.door_x][t->play.door_y] = '0';
		i = 1;
	}
	else
	{
		t->map.map[t->play.door_x][t->play.door_y] = '3';
		i = 0;
	}
}

void	ft_lose_life(t_cub3d *t)
{
	if (t->count_spr > 0)
	{
		if ((int)t->pos_x == 2
			&& (int)t->pos_y == 2)
		{
			t->play.life--;
			if (t->play.life <= 0)
			{
				write(1, "You Lose\n", 9);
				ft_close(t);
			}
		}
	}
}
