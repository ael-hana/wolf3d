/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:51:59 by ael-hana          #+#    #+#             */
/*   Updated: 2016/11/13 17:17:27 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_switch_fractal(t_env *ptr, t_fractal *f)
{
	if (ptr->switch_fractal == 1)
		ft_run_mandelbrot(ptr, f);
	if (ptr->switch_fractal == 2)
		ft_run_julia(ptr, f);
	if (ptr->switch_fractal == 3)
		ft_run_burn(ptr, f);
}

int		ft_exit_prog(t_env *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(1);
	return (0);
}

void	get_mlx_img(t_env *ptr)
{
	ptr->img.img = mlx_new_image(ptr->mlx, WINDOW_X, WINDOW_Y);
	ptr->img.data = mlx_get_data_addr(ptr->img.img, &(ptr->img.bpp),
			&(ptr->img.s_line), &(ptr->img.endian));
}
