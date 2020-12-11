/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:39:51 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 08:16:54 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_swap(t_sprite *spr1, t_sprite *spr2)
{
	t_sprite	spr3;

	spr3 = *spr1;
	*spr1 = *spr2;
	*spr2 = spr3;
}

double			ft_get_spr_dist(t_cub3d *t, int count)
{
	return ((t->pos_x - t->spr[count].x)\
		* (t->pos_x - t->spr[count].x)\
		+ (t->pos_y - t->spr[count].y)\
		* (t->pos_y - t->spr[count].y));
}

int				ft_count_sprites(t_cub3d *t)
{
	int	i;
	int	j;

	t->count_spr = 0;
	i = 0;
	while (i < t->map.rows)
	{
		j = 0;
		while (j < t->map.cols)
		{
			if (t->map.mapaux[i][j] == '2')
				t->count_spr++;
			j++;
		}
		i++;
	}
	return (t->count_spr);
}

void			ft_get_sprites(t_cub3d *t)
{
	int	count;
	int	i;
	int	j;

	count = ft_count_sprites(t);
	t->spr = (t_sprite *)malloc(sizeof(t_sprite) * count);
	i = -1;
	while (++i < t->map.rows)
	{
		j = -1;
		while (++j < t->map.cols)
		{
			if (t->map.mapaux[i][j] == '2')
			{
				count--;
				t->spr[count].x = i + 0.5;
				t->spr[count].y = j + 0.5;
				if (count % 2)
					t->spr[count].id = 0;
				else
					t->spr[count].id = 1;
				t->spr[count].dist = ft_get_spr_dist(t, count);
			}
		}
	}
}

void			ft_spr_sort(t_cub3d *t)
{
	int	i;

	i = 0;
	while (i + 1 < t->count_spr)
	{
		if (t->spr[i].dist < t->spr[i + 1].dist)
		{
			ft_swap(&t->spr[i], &t->spr[i + 1]);
			i = 0;
		}
		i++;
	}
}
