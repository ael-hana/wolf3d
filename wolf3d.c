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

void	ft_btn_event_2(int keycode, t_player *p)
{
	double	olddir_x;
	double	oldplane;

	if (keycode == KEY_LEFT)
	{
		olddir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(0.02) - p->dir_y * sin(0.02);
		p->dir_y = olddir_x * sin(0.02) + p->dir_y * cos(0.02);
		oldplane = p->plane_x;
		p->plane_x = oldplane * cos(0.02) - p->plane_y * sin(0.02);
		p->plane_y = oldplane * sin(0.02) + p->plane_y * cos(0.02);
	}
	else if (keycode == KEY_RIGHT)
	{
		olddir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-1 * 0.02) - p->dir_y * sin(-1 * 0.02);
		p->dir_y = olddir_x * sin(-1 * 0.02) + p->dir_y * cos(-1 * 0.02);
		oldplane = p->plane_x;
		p->plane_x = oldplane * cos(-1 * 0.02) - p->plane_y * sin(-1 * 0.02);
		p->plane_y = oldplane * sin(-1 * 0.02) + p->plane_y * cos(-1 * 0.02);
	}
}

int		ft_btn_event(int keycode, t_cam *c)
{
	t_env	*ptr;
	t_player	*p;

	ptr = c->ptr;
	p = c->ptr2;
	draw_map(c->ptr2, c);
	if (keycode == KEY_ESC)
		ft_exit_prog(ptr);
	if (keycode == KEY_UP)
	{
		if (map((int)(p->start_x + p->dir_x * 0.05),
		(int)p->start_y) == 0)
			p->start_x += (p->dir_x * 0.05);
		ft_putstr("Avant:\nx : "); ft_putnbr(p->start_x);
		if (map((int)p->start_x, (int)(p->start_y + p->dir_y * 0.05)) == 0)
			p->start_y += (p->dir_y * 0.05);
		ft_putstr("y : "); ft_putnbr(p->start_y);
		ft_putstr("\n");
	}
	else if (keycode == KEY_DOWN)
	{
		if (map((int)(p->start_x - p->dir_x * 0.05), (int)p->start_y) == 0)
			p->start_x -= (p->dir_x * 0.05);
		ft_putstr("x : "); ft_putnbr(p->start_x);
		if (map((int)p->start_x, (int)(p->start_y - p->dir_y * 0.05)) == 0)
			p->start_y -= (p->dir_y * 0.05);
		ft_putstr("y : "); ft_putnbr(p->start_y);
		ft_putstr("\n");
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_btn_event_2(keycode, p);
	else
		return (0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	//display_menu(ptr);
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

void	pixel_put_to_image(t_cam *c, int x, int y, int color)
{
	int		pos;
	t_env	*ptr;

	ptr = c->ptr;
	pos = (y * ptr->s_line) + (x * (ptr->bpp / 8));
	if (!ptr->endian)
	{
		ptr->data[pos] = color & 0x0000FF;
		ptr->data[pos + 1] = (color & 0x00FF00) >> 8;
		ptr->data[pos + 2] = (color & 0xFF0000) >> 16;
	}
	else
	{
		ptr->data[pos] = (color & 0xFF0000) >> 16;
		ptr->data[pos + 1] = (color & 0x00FF00) >> 8;
		ptr->data[pos + 2] = color & 0x0000FF;
	}
}

int		map(int x, int y)
{
	static int	worldmap[20][20] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	return (worldmap[x][y]);
}

void	int_cam(int x, t_cam *c, t_player *p){
	c->camera_x = 2 * x / (double)(WINDOW_X) - 1;
	c->raypos_x = p->start_x;
	c->raypos_y = p->start_y;
	c->raydir_x = p->dir_x + p->plane_x * c->camera_x;
	c->raydir_y = p->dir_y + p->plane_y * c->camera_x;
	c->map_x = (int)c->raypos_x;
	c->map_y = (int)c->raypos_y;
	c->deltadist_x = sqrt(1 + (c->raydir_y * c->raydir_y) /
					(c->raydir_x * c->raydir_x));
	c->deltadist_y = sqrt(1 + (c->raydir_x * c->raydir_x) /
					(c->raydir_y * c->raydir_y));
	c->hit = 0;
}

void	check_ray(t_player *p, t_cam *c)
{
	if (c->raydir_x < 0)
	{
		p->step_x = -1;
		c->sidedist_x = (c->raypos_x - (double)c->map_x) * c->deltadist_x;
	}
	else
	{
		p->step_x = 1;
		c->sidedist_x = ((double)c->map_x + 1.0 - c->raypos_x) * c->deltadist_x;
	}
	if (c->raydir_y < 0)
	{
		p->step_y = -1;
		c->sidedist_y = (c->raypos_y - (double)c->map_y) * c->deltadist_y;
	}
	else
	{
		p->step_y = 1;
		c->sidedist_y = ((double)c->map_y + 1 - c->raypos_y) * c->deltadist_y;
	}
}

void		color_1(t_player *p, t_cam *c)
{
	if (c->side == 0)
	{
		if (p->step_x <= 0)
			c->color = 0xFF0000;
		else
			c->color = 0xFFFF00;
	}
	else
	{
		if (p->step_y <= 0)
			c->color = 0x00FF00;
		else
			c->color = 0x0000FF;
	}
}

void		color_2(t_player *p, t_cam *c)
{
	if (c->side == 0)
	{
		if (p->step_x <= 0)
			c->color = 0x5AB479;
		else
			c->color = 0x5AB4A6;
	}
	else
	{
		if (p->step_y <= 0)
			c->color = 0x5A95B4;
		else
			c->color = 0x5A68B4;
	}
}

void	calcul_length(t_player *p, t_cam *c)
{
	if (c->side == 0)
		c->perpwalldist = fabs((c->map_x - c->raypos_x + (1 - p->step_x) / 2)
							/ c->raydir_x);
	else
		c->perpwalldist = fabs((c->map_y - c->raypos_y + (1 - p->step_y) / 2) / c->raydir_y);
	c->lineheigth = abs((int)(WINDOW_Y / c->perpwalldist));
	c->drawstart = (-1 * c->lineheigth) / 2 + WINDOW_Y / 2;
	if (c->drawstart < 0)
		c->drawstart = 0;
	c->drawend = c->lineheigth / 2 + WINDOW_Y / 2;
	if (c->drawend >= WINDOW_Y)
		c->drawend = WINDOW_Y - 1;
	if (c->side == 1)
		color_1(p, c);
	else
		color_2(p, c);
}

void	calcul_hit(t_player *p, t_cam *c)
{
	while (c->hit == 0)
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

void	draw_line_verticale(int x, t_cam *c)
{
	int	y;

	y = c->drawstart;
	while (c->drawend > y)
	{
		pixel_put_to_image(c, x, y, c->color);
		++y;
	}
	y = c->drawend;
	while (WINDOW_Y > y)
	{
		pixel_put_to_image(c, x, WINDOW_Y - y - 1, 0xCFECF2);
		pixel_put_to_image(c, x, y, 0xCCAAFF);
		++y;
	}
}

void	draw_map(t_player *p, t_cam *c)
{
	int	x;

	x = 0;
	while (x < WINDOW_X)
	{
		int_cam(x, c, p);
		check_ray(p, c);
		calcul_hit(p, c);
		draw_line_verticale(x, c);
		++x;
	}
}

int		main(/*int ac, char **av*/)
{
	t_env		s;
	t_cam		c;
	t_player	p;

	p.start_x = 18;
	p.start_y = 18;
	p.dir_x = -1;
	p.dir_y = 0;
	p.plane_x = 0.0;
	p.plane_y = 0.66;
	//p.time = 0;
	//p.oldtime = 0;
	c.ptr = &s;
	c.ptr2 = &p;
	init_mlx(&s);
	draw_map(&p, &c);
	mlx_put_image_to_window(s.mlx, s.win, s.img, 0, 0);
	mlx_hook(s.win, DESTROY_NOTIFY, DESTROY_MASK, ft_exit_prog, &s);
	mlx_key_hook(s.win, ft_btn_event, &c);
	mlx_loop(s.mlx);
	return (0);
}
