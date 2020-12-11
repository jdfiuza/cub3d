/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:43:09 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 07:41:36 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_texture(t_cub3d *t)
{
	if (t->flagtex == 1)
		t->flagtex = 0;
	else
		t->flagtex = 1;
}

static void	ft_open_door(t_cub3d *t)
{
	ft_secret(t);
	ft_door(t);
}

int			key_press(int keycode, t_cub3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->moves.up = 1;
	else if (keycode == 1 || keycode == 125)
		t->moves.down = 1;
	else if (keycode == 124)
		t->moves.right = 1;
	else if (keycode == 123)
		t->moves.left = 1;
	else if (keycode == 0)
		t->moves.ldesp = 1;
	else if (keycode == 2)
		t->moves.rdesp = 1;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.1;
	else if (keycode == 53)
		ft_close(t);
	else if (keycode == 35)
		ft_texture(t);
	else if (keycode == 49)
		ft_open_door(t);
	else if (keycode == 15)
		ft_play_barrel(t);
	else if (keycode == 257)
		t->ms = 0.5;
	return (0);
}

int			key_release(int keycode, t_cub3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->moves.up = 0;
	else if (keycode == 1 || keycode == 125)
		t->moves.down = 0;
	else if (keycode == 124)
		t->moves.right = 0;
	else if (keycode == 123)
		t->moves.left = 0;
	else if (keycode == 2)
		t->moves.rdesp = 0;
	else if (keycode == 0)
		t->moves.ldesp = 0;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.03;
	return (0);
}

int			mouse_move(int x, int y, t_cub3d *t)
{
	if (x < 300 && y > 150 && y < 350)
		t->moves.mleft = 1;
	else if (x > 550 && y > 150 && y < 350)
		t->moves.mright = 1;
	else
	{
		t->moves.mleft = 0;
		t->moves.mright = 0;
	}
	if (x > 250 && x < 650 && y < 100)
		t->moves.look_up = 1;
	else if (x > 250 && x < 650 && y > 380)
		t->moves.look_down = 1;
	else
	{
		t->moves.look_up = 0;
		t->moves.look_down = 0;
	}
	return (x);
}
