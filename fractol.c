/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:02:37 by ael-hana          #+#    #+#             */
/*   Updated: 2016/11/13 18:08:14 by ael-hana         ###   ########.fr       */
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
	ptr->win = mlx_new_window(ptr->mlx, WINDOW_X, WINDOW_Y, "fractol");
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

int		main(int ac, char **av)
{
	t_env		s;
	int worldMap[24][24]=
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
	t_player	p;

	p.start_x = 22;
	p.start_y = 12;
	init_mlx(&s);
	mlx_put_image_to_window(s.mlx, s.win, s.img, 0, 0);
	mlx_hook(s.win, DESTROY_NOTIFY, DESTROY_MASK, ft_exit_prog, &s);
	mlx_key_hook(s.win, ft_btn_event, &s);
	mlx_loop(s.mlx);
	return (0);
}
