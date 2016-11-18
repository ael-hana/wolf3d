/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:37 by ael-hana          #+#    #+#             */
/*   Updated: 2016/11/18 20:29:22 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*void	ft_btn_event_2(int keycode, t_fractal *f)
{
	if (keycode == KEY_UP)
	{
		f->y1 -= 0.01;
		f->y2 -= 0.01;
	}
	else if (keycode == KEY_DOWN)
	{
		f->y1 += 0.01;
		f->y2 += 0.01;
	}
	else if (keycode == KEY_LEFT)
	{
		f->x1 -= 0.01;
		f->x2 -= 0.01;
	}
	else if (keycode == KEY_RIGHT)
	{
		f->x1 += 0.01;
		f->x2 += 0.01;
	}
}
*/
int		ft_btn_event(int keycode, t_env *ptr)
{
/*	t_env	*ptr;

	ptr = f->ptr;
	if (keycode == KEY_NUM_PLUS)
		f->zoom += 100;
	else if (keycode == KEY_NUM_MINUS)
		f->zoom -= 100;
	else */if (keycode == KEY_ESC)
		ft_exit_prog(ptr);/*
	else if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_btn_event_2(keycode, f);
	else if (keycode == KEY_MIN)
		f->it_max -= 10;
	else if (keycode == KEY_EQUAL)
		f->it_max += 10;
	else if (keycode == KEY_C)
		++ptr->opt;
	else
		return (0);
	ft_switch_fractal(ptr, f);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, 0, 0);
	display_menu(ptr);*/
	return (0);
}

int		ft_exit_prog(t_env *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(1);
	return (0);
}

void	get_mlx_img(t_env *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx, WINDOW_X, WINDOW_Y);
	ptr->data = mlx_get_data_addr(ptr->img, &(ptr->bpp),
			&(ptr->s_line), &(ptr->endian));
}

void	init_mlx(t_env *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, WINDOW_X, WINDOW_Y, "WOLF3D");
	get_mlx_img(ptr);
}

void	pixel_put_to_image(t_env *ptr, int x, int y)
{
	int		pos;

	pos = (x * (ptr->bpp / 8)) + (y * ptr->s_line);
	/*if ((ptr->opt % 3) == 0)
	{*/
		ptr->data[pos] = (int)ptr->color;
		ptr->data[pos + 1] = (int)ptr->color >> 8;
		ptr->data[pos + 2] = (int)ptr->color >> 16;
	/*}
	else if ((ptr->opt % 3) == 1)
	{
		ptr->img.data[pos] = (int)ptr->color >> 16;
		ptr->img.data[pos + 1] = (int)ptr->color >> 8;
		ptr->img.data[pos + 2] = (int)ptr->color;
	}
	else
	{
		ptr->img.data[pos] = (int)ptr->color >> 8;
		ptr->img.data[pos + 1] = (int)ptr->color;
		ptr->img.data[pos + 2] = (int)ptr->color >> 16;
	}*/
}

int		map(int x, int y)
{
	static int worldMap[24][24]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	return (worldMap[x][y]);
}

void	int_cam(int x, t_cam *c, t_player *p){
	c->camera_x = 2 * x / (double)WINDOW_X - 1;
	c->raypos_x = p->start_x;
	c->raypos_y = p->start_y;
	c->raydir_x = p->dir_x + p->plane_x * c->camera_x;
	c->raydir_y = p->dir_y + p->plane_y * c->camera_x;
	c->deltadist_x = sqrt(1 + (c->raydir_y * c->raydir_y) / (c->raydir_x * c->raydir_x));
	c->deltadist_y = sqrt(1 + (c->raydir_x * c->raydir_x) / (c->raydir_y * c->raydir_y));
	c->hit = 0;
	c->map_x = (int)c->raypos_x;
	c->map_y = (int)c->raypos_y;
}

void	check_ray(t_player *p, t_cam *c)
{
	if (c->raydir_x < 0)
	{
		p->step_x = -1;
		c->sidedist_x = (c->raypos_x - c->map_x) * c->deltadist_x;
	}
	else
	{
		p->step_x = 1;
		c->sidedist_x = (c->map_x + 1 - c->raypos_x) * c->deltadist_x;
	}
	if (c->raydir_y < 0)
	{
		p->step_y = -1;
		c->sidedist_y = (c->raypos_y - c->map_y) * c->deltadist_y;
	}
	else
	{
		p->step_y = 1;
		c->sidedist_y = (c->map_y + 1 - c->raypos_y) * c->deltadist_y;
	}
}

void	calcul_length(t_player *p, t_cam *c)
{
	if (c->side == 0)
		c->perpwalldist = (c->map_x - c->raypos_x + (1 - p->step_x) / 2) / c->raydir_x;
	else
		c->perpwalldist = (c->map_y - c->raypos_y + (1 - p->step_y) / 2) / c->raydir_y;
	c->lineheigth = (WINDOW_Y / c->perpwalldist);
	c->drawstart = -c->lineheigth / 2 + WINDOW_Y / 2;
	if (c->drawstart < 0)
		c->drawstart = 0;
	c->drawend = c->lineheigth / 2 + WINDOW_Y / 2;
	if (c->drawend >= WINDOW_Y)
		c->drawend = WINDOW_Y - 1;
	if (c->side == 1)
	{
		>>.....<<
	}
}

void	calcul_hit(t_player *p, t_cam *c)
{
	while (!c->hit)
	{
		if (c->sidedist_x < c->sidedist_y)
		{
			c->sidedist_x += c->deltadist_x;
			c->map_x += p->step_x;
			c->side = 0;
		}
		else
		{
			c->sidedist_y += c->deltadist_y;
			c->map_y += p->step_y;
			c->side = 1;
		}
		if (map(c->map_x, c->map_y) > 0)
			c->hit = 1;
	}
	calcul_length(p, c);
}

void	draw_map(t_player *p, t_cam *c){
	int	x;

	x = 0;
	while (x < WINDOW_X)
	{
		int_cam(x, c, p);
		check_ray(p, c);
		calcul_hit(p, c);
		++x;
	}
}

int		main(int ac, char **av)
{
	t_env		s;
	t_cam		c;
	t_player	p;

	p.start_x = 22;
	p.start_y = 12;
	p.dir_x = -1;
	p.dir_y = 0;
	p.plane_x = 0;
	p.plane_y = 0.66;
	p.time = 0;
	p.oldtime = 0;

	init_mlx(&s);
	mlx_put_image_to_window(s.mlx, s.win, s.img, 0, 0);
	mlx_hook(s.win, DESTROY_NOTIFY, DESTROY_MASK, ft_exit_prog, &s);
	mlx_key_hook(s.win, ft_btn_event, &s);
	mlx_loop(s.mlx);
	return (0);
}
