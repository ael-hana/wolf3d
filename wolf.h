/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:00:00 by ael-hana          #+#    #+#             */
/*   Updated: 2016/11/18 15:51:51 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# include "keyboard.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# define WOLF_H
# define WINDOW_X 800
# define WINDOW_Y 600
# define DESTROY_NOTIFY 17
# define DESTROY_MASK (1L<<17)

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					color;
	int					bpp;
	int					s_line;
	int					endian;
	void				*img;
	char				*data;
	char				*mlx_map;
}						t_env;

typedef struct			s_player
{
	int					start_x;
	int					start_y;
	int					step_x;
	int					step_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				time;
	double				oldtime;
}						t_player;

typedef struct			s_cam
{
	double				camera_x;
	double				raypos_x;
	double				raypos_y;
	double				raydir_x;
	double				raydir_y;
	int					map_x;
	int					map_y;
	double				deltadist_x;
	double				deltadist_y;
	double				sidedist_x;
	double				sidedist_y;
	int					side;
	int					hit;
}						t_cam;
int						ft_exit_prog(t_env *ptr);
#endif
