/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:43:09 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/29 09:33:49 by jheras-f         ###   ########.fr       */
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
		t->ms = 0.05;
	return (0);
}
