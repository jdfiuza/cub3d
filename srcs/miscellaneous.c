/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:39:20 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/28 07:34:28 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_get_pos(t_cub3d *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < t->map.rows)
	{
		while (j < t->map.cols)
		{
			if ((t->map.map[i][j] < '0' || t->map.map[i][j] > '9')
					&& (t->map.map[i][j] > ' '))
			{
				t->pos_x = (double)i;
				t->pos_y = (double)j;
				t->orien = t->map.map[i][j];
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void		ft_set_values(t_cub3d *t)
{
	if (t->orien == 'E')
	{
		t->dir_x = 0;
		t->dir_y = 1;
		t->plane_x = 0.66;
		t->plane_y = 0;
	}
	else if (t->orien == 'W')
	{
		t->dir_x = 0;
		t->dir_y = -1;
		t->plane_x = -0.66;
		t->plane_y = 0;
	}
}

void			ft_set_player_pos(t_cub3d *t)
{
	if (t->orien == 'N')
	{
		t->dir_x = -1;
		t->dir_y = 0;
		t->plane_x = 0;
		t->plane_y = 0.66;
	}
	else if (t->orien == 'S')
	{
		t->dir_x = 1;
		t->dir_y = 0;
		t->plane_x = 0;
		t->plane_y = -0.66;
	}
	else
		ft_set_values(t);
}
