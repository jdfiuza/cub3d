/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:27:05 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/28 13:50:19 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_save_arg(t_cub3d *t, char *argv[])
{
	if (!(ft_strcmp(argv[2], "--save")))
	{
		t->saved_img = 0;
		if (open(argv[1], O_WRONLY) > 0)
			ft_get_data(argv[1], t);
		else
		{
			write(1, "Error\nInvalid map file", 22);
			return (1);
		}
	}
	else
	{
		write(1, "Error\nNot valid option, [path/map][--save]\n", 43);
		return (1);
	}
	return (0);
}

int		ft_check_map_arg(t_cub3d *t, char *argv[])
{
	t->saved_img = 1;
	if (open(argv[1], O_WRONLY) > 0)
		ft_get_data(argv[1], t);
	else
	{
		write(1, "Error\nInvalid map file", 22);
		return (1);
	}
	return (0);
}

int		ft_check_config(t_cub3d *t)
{
	if (ft_check_resol(t))
	{
		write(1, "Error\nBad Resolution configuration\n", 35);
		return (1);
	}
	if (ft_check_floor_color(t))
	{
		write(1, "Error\nBad floor color configuration\n", 35);
		return (1);
	}
	if (ft_check_ceilin_color(t))
	{
		write(1, "Error\nBad ceil color configuration\n", 35);
		return (1);
	}
	return (0);
}

int		ft_check_general(t_cub3d *t, int args, char *argv[])
{
	if (args < 2 || args > 3)
	{
		write(1, "Error\nNumber of arg invalid. Try [--save] [path/map]\n", 56);
		return (1);
	}
	else if (args == 3)
	{
		if (ft_check_save_arg(t, argv))
			return (1);
	}
	else if (args == 2)
	{
		if (ft_check_map_arg(t, argv))
			return (1);
	}
	if (ft_check_config(t))
		return (1);
	return (0);
}
