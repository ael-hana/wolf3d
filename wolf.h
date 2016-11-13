/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:00:00 by ael-hana          #+#    #+#             */
/*   Updated: 2016/11/13 18:08:13 by ael-hana         ###   ########.fr       */
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
	int					start_x;
	int					start_y;
}						t_player;
int						ft_exit_prog(t_env *ptr);
#endif
