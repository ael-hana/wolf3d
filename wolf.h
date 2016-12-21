/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:52:50 by ael-hana          #+#    #+#             */
/*   Updated: 2016/12/21 08:52:52 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define WIDTH				1000
# define HEIGHT				800
# define ECHAP				53
# define KEY_UP				126
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_T				17
# define KEY_H				4
# define KEY_A				0
# define KEY_D				2
# define KEYRELEASE 		3
# define KEYRELEASE_MASK	(1L<<1)
# define KEYPRESS 			2
# define KEYPRESS_MASK		(1L<<0)
# define EXPOSE				12
# define EXPOSE_MASK		(1L<<15)
# define DESTROY_NOTIFY		17
# define DESTROY_MASK		(1L<<17)

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
}					t_img;

typedef struct		s_dir
{
	int				up;
	int				right;
	int				down;
	int				left;
}					t_dir;

typedef	struct		s_w3d
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_pos_x;
	int				map_pos_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			step_x;
	double			step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				line_height;
	int				start;
	int				end;
	int				hit;
	int				side;
}					t_w3d;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				help;
	t_img			img;
	t_dir			key;
	t_w3d			*wolf;
	int				change;
	int				color;
}					t_env;
void				ft_msg_error(char *msg);
int					key_hook(int keycode, t_env *e);
int					key_press(int keycode, t_env *e);
int					run_hook(t_env *e);
void				pixel_put_to_image(t_env *e, double x, double y, int color);
void				color_1(t_env *e);
void				color_2(t_env *e);
void				display_menu(t_env *e);
int					quit_program(t_env *e);
int					map(int x, int y);
t_w3d				*init_w3d();
void				init_env(t_env *e);
void				init_img(t_env *e);
void				draw_map(t_env *e);
void				straffe_left(t_env *e);
void				straffe_right(t_env *e);
void				move_up(t_env *e);
void				move_right(t_env *e);
void				move_down(t_env *e);
void				move_left(t_env *e);
void				move(t_env *e);
int					draw_y(t_env *e, double x, int start, int end);
#endif
