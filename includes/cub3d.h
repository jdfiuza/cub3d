/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:20:32 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 07:48:16 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "../gnl/get_next_line.h"
# include "../minilibx/mlx.h"
# include "key.h"
# include "img.h"
# define MAX_WIDTH 1920
# define MIN_WIDTH 200
# define MAX_HEIGHT 1080
# define MIN_HEIGHT 200

typedef struct	s_map
{
	char		**map;
	char		**mapaux;
	char		*ntext;
	char		*stext;
	char		*wtext;
	char		*etext;
	char		*sprite;
	char		*sprite2;
	char		**resol;
	char		**floor;
	char		**ceil;
	char		r;
	char		f;
	char		c;
	int			rows;
	int			cols;
	int			res_x;
	int			res_y;
	int			f_color;
	int			c_color;
}				t_map;

typedef struct	s_moves
{
	int			up;
	int			down;
	int			right;
	int			left;
	int			look_up;
	int			look_down;
	int			mright;
	int			mleft;
	int			ldesp;
	int			rdesp;
	int			lclick;
	int			rclick;
}				t_moves;

typedef struct	s_textures
{
	void		*im;
	char		*ptr;
	int			bpp;
	int			szln;
	int			endian;
}				t_textures;

typedef struct	s_tex
{
	int			size;
	int			start;
	int			end;
}				t_tex;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
	double		spr_x;
	double		spr_y;
	double		trf_x;
	double		trf_y;
	int			width;
	int			height;
	int			hg;
	int			wd;
	int			texture;
	int			screen_x;
	int			id;
}				t_sprite;

typedef	struct	s_player
{
	int			life;
	int			door_x;
	int			door_y;
}				t_player;

typedef struct	s_cub3d
{
	void		*ptr;
	void		*win;
	char		**levels;
	char		orien;
	int			exit_code;
	int			map_x;
	int			map_y;
	int			flagtex;
	int			step_x;
	int			step_y;
	int			text_x;
	int			text_y;
	int			side;
	int			start;
	int			end;
	int			hit;
	int			id;
	int			y;
	int			x;
	int			color;
	int			lineheight;
	int			count_spr;
	int			saved_img;
	double		deltadist_x;
	double		deltadist_y;
	double		raydir_x;
	double		raydir_y;
	double		raypos_x;
	double		raypos_y;
	double		sidedist_x;
	double		sidedist_y;
	double		cam_x;
	double		cam_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		olddir_x;
	double		olddir_y;
	double		plane_x;
	double		plane_y;
	double		oldplane_x;
	double		wall_x;
	double		wall_y;
	double		walldist;
	double		ms;
	double		rs;
	double		tmpdir;
	double		tmpdir_x;
	double		tmpdir_y;
	double		*dists;
	double		inv_det;
	int			points;

	t_sprite	*spr;
	t_map		map;
	t_moves		moves;
	t_textures	img[11];
	t_player	play;
}				t_cub3d;

int				key_press(int keycode, t_cub3d *t);
int				key_release(int keycode, t_cub3d *t);
int				ft_color(char *r, char *g, char *b);
void			ft_init_basic(t_cub3d *t);
void			ft_init_cub(t_cub3d *cub3d);
void			ft_init(t_cub3d *t);
void			ft_count_rows(char *path, t_cub3d *t);
void			ft_get_map(char *line, t_cub3d *t);
void			ft_get_data(char *path, t_cub3d *t);
int				ft_atoi(const char *s);
char			*ft_itoa(int nbr);
int				ft_isnum(char *s1);
char			*ft_substr(const char *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_split(const char *s, char c);
char			*ft_strdup(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_load_images(t_cub3d *t);
void			ft_put_ceilin(t_cub3d *t);
void			ft_put_floor(t_cub3d *t);
void			ft_put_wall(int x, int start, int end, t_cub3d *t);
void			ft_draw_texture(t_cub3d *t, int x, int spr_start, int color);
void			ft_init_dda(t_cub3d *t);
void			ft_dda(t_cub3d *t);
void			ft_init_raycasting(t_cub3d *t, int i);
void			ft_floor_ceilin(t_cub3d *t, int i);
void			ft_raycasting(t_cub3d *t);
int				ft_move(t_cub3d *t);
void			ft_rotate(t_cub3d *t);
void			ft_get_pos(t_cub3d *t);
void			ft_set_player_pos(t_cub3d *t);
void			ft_sort_sprites(t_cub3d *t);
int				ft_close(t_cub3d *t);
void			ft_save_img(t_cub3d *t);
int				ft_validate_map(t_cub3d *t);
void			ft_process_map(char *path, t_cub3d *t);
int				ft_check_config(t_cub3d *t);
int				ft_check_resol(t_cub3d *t);
int				ft_check_floor_color(t_cub3d *t);
int				ft_check_ceilin_color(t_cub3d *t);
int				ft_check_save_arg(t_cub3d *t, char *argv[]);
int				ft_check_map_arg(t_cub3d *t, char *argv[]);
int				ft_check_general(t_cub3d *t, int args, char *argv[]);
void			ft_aux_raycasting(t_cub3d *t);
void			ft_secret(t_cub3d *t);
void			ft_play_barrel(t_cub3d *t);
void			ft_process_map_aux(t_cub3d *t);
void			ft_put_image(t_cub3d *t);
void			ft_get_sprites(t_cub3d *t);
void			ft_spr_sort(t_cub3d *t);
int				ft_count_sprites(t_cub3d *t);
double			ft_get_spr_dist(t_cub3d *t, int count);
void			ft_draw_sprites(t_cub3d *t);
void			ft_draw_texture_h(t_cub3d *t, int x, int tex_x, t_tex hg);
void			ft_draw_sprite(t_cub3d *t, int count);
void			ft_get_trasnform(t_cub3d *t, int count);
void			ft_put_sprite_pixel(t_cub3d *t, int x, int start, int color);
unsigned int	ft_get_color(t_cub3d *t, int x, int y);
t_tex			ft_get_spr_wd(t_cub3d *t, int count);
t_tex			ft_get_spr_hg(t_cub3d *t, int count);
int				mouse_move(int x, int y, t_cub3d *t);
void			ft_earn_points(t_cub3d *t);
void			ft_look(t_cub3d *t);
void			ft_animation(t_cub3d *t);
void			ft_door(t_cub3d *t);
void			ft_lose_life(t_cub3d *t);
#endif
