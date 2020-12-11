/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:16:41 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 07:29:38 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_color(char *cr, char *cg, char *cb)
{
	int r;
	int g;
	int b;
	int	rgb;

	r = ft_atoi(cr);
	g = ft_atoi(cg);
	b = ft_atoi(cb);
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

void	ft_count_rows(char *path, t_cub3d *t)
{
	int		fd;
	char	*tmp;

	t->map.rows = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		if (tmp[0] == '1')
			t->map.rows++;
		free(tmp);
	}
	free(tmp);
	close(fd);
}

void	ft_get_map(char *ln, t_cub3d *t)
{
	static int	i = 0;
	int			j;
	char		tmp[ft_strlen(ln)];

	j = 0;
	if (!(ft_strlen(ln)))
	{
		t->map.map[i] = ft_strdup("0");
		i++;
		return ;
	}
	while (*ln != '\0')
	{
		if (*ln != ' ')
		{
			tmp[j] = *ln;
			j++;
		}
		ln++;
	}
	tmp[j] = '\0';
	t->map.cols = (int)(ft_strlen(tmp)) + 1;
	t->map.map[i] = ft_strdup(tmp);
	i++;
}

void	ft_process_map_aux(t_cub3d *t)
{
	int		i;
	int		j;

	if (!(t->map.mapaux = (char **)malloc(sizeof(char *) * t->map.rows)))
		return ;
	i = 0;
	while (i < t->map.rows)
	{
		j = 0;
		t->map.mapaux[i] = (char *)malloc(sizeof(char) * t->map.cols);
		while (j < t->map.cols)
		{
			t->map.mapaux[i][j] = t->map.map[i][j];
			j++;
		}
		i++;
	}
}

void	ft_process_map(char *path, t_cub3d *t)
{
	int		fd;
	char	*tmp;
	int		flag;

	flag = 0;
	ft_count_rows(path, t);
	if (!(t->map.map = (char **)malloc(sizeof(char *) * t->map.rows)))
		return ;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		if (tmp[0] == '1' && flag == 0)
			flag = 1;
		if (flag == 1)
			ft_get_map(tmp, t);
		free(tmp);
	}
	close(fd);
	free(tmp);
}
