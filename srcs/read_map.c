/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:25:40 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/28 15:08:47 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_get_path(char *ln, char *text)
{
	ln += 2;
	while (*ln == ' ')
		ln++;
	if (ft_strlen(ln) == 0)
		text = ft_strdup("");
	else
		text = ft_strdup(ln);
	return (text);
}

static void	ft_get_r_values(char *ln, t_cub3d *t)
{
	t->map.r = 'R';
	if (ln[0] == 'R')
	{
		t->map.resol = ft_split(ln, ' ');
		t->map.res_x = ft_atoi(t->map.resol[1]);
		t->map.res_y = ft_atoi(t->map.resol[2]);
	}
}

static void	ft_get_c_values(char *ln, t_cub3d *t)
{
	if (ln[0] == 'F')
	{
		t->map.f = 'F';
		while (*ln < '0' || *ln > '9')
			ln++;
		t->map.floor = ft_split(ln, ',');
	}
	else if (ln[0] == 'C')
	{
		t->map.c = 'C';
		while (*ln < '0' || *ln > '9')
			ln++;
		t->map.ceil = ft_split(ln, ',');
	}
}

static void	ft_get_param(char *ln, t_cub3d *t)
{
	if (ln[0] == 'R')
		ft_get_r_values(ln, t);
	else if (ln[0] == 'N' && ln[1] == 'O')
		t->map.ntext = ft_get_path(ln, t->map.ntext);
	else if (ln[0] == 'S' && ln[1] == 'O')
		t->map.stext = ft_get_path(ln, t->map.stext);
	else if (ln[0] == 'W' && ln[1] == 'E')
		t->map.wtext = ft_get_path(ln, t->map.wtext);
	else if (ln[0] == 'E' && ln[1] == 'A')
		t->map.etext = ft_get_path(ln, t->map.etext);
	else if (ln[0] == 'S' && ln[1] == ' ')
		t->map.sprite = ft_get_path(ln, t->map.sprite);
	else if ((ln[0] == 'F' && ln[1] == ' ') || (ln[0] == 'C' && ln[1] == ' '))
		ft_get_c_values(ln, t);
}

void		ft_get_data(char *path, t_cub3d *t)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		ft_get_param(tmp, t);
		free(tmp);
	}
	free(tmp);
	close(fd);
	ft_process_map(path, t);
	ft_process_map_aux(t);
	if (t->map.f == 'F')
		t->map.f_color = ft_color(t->map.floor[0], t->map.floor[1],
			t->map.floor[2]);
	if (t->map.c == 'C')
		t->map.c_color = ft_color(t->map.ceil[0], t->map.ceil[1],
			t->map.ceil[2]);
}
