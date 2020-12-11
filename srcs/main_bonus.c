/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:55:22 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/30 14:15:22 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int args, char *argv[])
{
	t_cub3d t;

	ft_init_basic(&t);
	if (ft_check_general(&t, args, argv))
		return (1);
	ft_init_cub(&t);
	ft_init(&t);
	if (ft_validate_map(&t))
	{
		write(1, "Error\nInvalid Map\n", 19);
		ft_close(&t);
		return (1);
	}
	t.flagtex = 1;
	mlx_hook(t.win, 17, 0L, &ft_close, &t);
	mlx_hook(t.win, 2, 1L << 0, &key_press, &t);
	mlx_hook(t.win, 3, 1L << 1, &key_release, &t);
	mlx_hook(t.win, 6, 1L << 6, &mouse_move, &t);
	ft_load_images(&t);
	ft_raycasting(&t);
	mlx_loop_hook(t.ptr, &ft_move, &t);
	mlx_loop(t.ptr);
	return (0);
}
