/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:58:19 by ael-hana          #+#    #+#             */
/*   Updated: 2016/11/12 21:33:01 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_slide(int x, int y, t_fractal *f)
{
	t_env	*ptr;

	ptr = f->ptr;
	ptr->mouse_x = ((((f->x2 - f->x1) * x) / (WINDOW_X / 4)) + f->x1);
	ptr->mouse_y = ((((f->y2 - f->y1) * y) / (WINDOW_Y / 4)) + f->y1);
	ft_switch_fractal(ptr, f);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, 0, 0);
	display_menu(ptr);
	return (0);
}

void	ft_run_julia(t_env *ptr, t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			ft_julia(ptr, x, y, f);
			pixel_put_to_image(ptr, x, y);
			x++;
		}
		y++;
	}
}

void	ft_julia(t_env *ptr, int x, int y, t_fractal *f)
{
	f->c_r = ptr->mouse_x;
	f->c_i = ptr->mouse_y;
	f->z_r = x / f->zoom + f->x1;
	f->z_i = y / f->zoom + f->y1;
	f->i = 0;
	while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->it_max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2.0 * f->tmp * f->z_i + f->c_i;
		++f->i;
	}
	if (f->i == f->it_max)
		set_color(ptr, 0);
	else
		set_color(ptr, (f->i % 256) * 255 / f->it_max);
}

void	init_value_julia(t_fractal *f)
{
	f->it_max = 10;
	f->x1 = -2;
	f->x2 = 2;
	f->y1 = -2;
	f->y2 = 2;
}
