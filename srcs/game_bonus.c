/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:45:56 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 07:39:56 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_trim_spaces(char *ln, int pos, t_cub3d *t)
{
	int i;
	int j;

	i = 0;
	j = 0;
	t->map.mapaux[pos] = (char *)malloc(sizeof(char) * t->map.cols);
	while (ln[i] != '\0')
	{
		if (ln[i] != ' ')
		{
			t->map.mapaux[pos][j] = ln[i];
			j++;
		}
		i++;
	}
	t->map.mapaux[pos][j] = '\0';
}

static void		ft_get_new_map(char *path, t_cub3d *t)
{
	int		fd;
	char	*tmp;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	if (!(t->map.mapaux = (char **)malloc(sizeof(char *) * t->map.rows)))
		return ;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		if (tmp[0] == '1' && flag == 0)
			flag = 1;
		if (flag == 1)
		{
			ft_trim_spaces(tmp, i, t);
			i++;
		}
		free(tmp);
	}
	close(fd);
	free(tmp);
}

void			ft_put_level(t_cub3d *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->map.rows)
	{
		j = 0;
		while (j < t->map.cols)
		{
			if (t->map.mapaux[i][j] == '1')
				t->map.map[i][j] = '1';
			else
				t->map.map[i][j] = '0';
			j++;
		}
		t->pos_x = 2.0;
		t->pos_y = 2.0;
		i++;
	}
}

void			ft_new_level(t_cub3d *t)
{
	static int	level = 0;
	int			i;

	i = 0;
	while (i < t->map.rows)
	{
		free(t->map.mapaux[i]);
		i++;
	}
	free(t->map.mapaux);
	if (level < 2)
	{
		ft_get_new_map(t->levels[level], t);
		ft_put_level(t);
		free(t->spr);
		level++;
	}
	else
		ft_close(t);
}

void			ft_play_barrel(t_cub3d *t)
{
	int i;

	i = 0;
	while (i < t->count_spr)
	{
		if ((int)t->pos_x == (int)t->spr[i].x
				&& (int)t->pos_y == (int)t->spr[i].y)
		{
			t->map.mapaux[(int)t->spr[i].x][(int)t->spr[i].y] = '0';
			t->points += 10;
			free(t->spr);
			ft_get_sprites(t);
			ft_spr_sort(t);
		}
		i++;
	}
	if (t->count_spr == 0)
	{
		ft_new_level(t);
		ft_get_sprites(t);
		ft_spr_sort(t);
		ft_raycasting(t);
	}
}
