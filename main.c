/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:52:35 by ael-hana          #+#    #+#             */
/*   Updated: 2016/12/21 08:53:28 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				quit_program(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
	return (0);
}

void			display_menu(t_env *e)
{
	int			x;
	int			y;

	x = 0;
	while (x++ < 400)
	{
		y = 0;
		while (y++ < 100)
			pixel_put_to_image(e, x, y, 0x000000);
	}
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFF00, "h : Aide");
	if (e->help == 1)
	{
		mlx_string_put(e->mlx, e->win, 10, 30, 0xF8F8FF,
			"Echap - Croix : Exit");
		mlx_string_put(e->mlx, e->win, 10, 45, 0xF8F8FF,
			"Fleche        : Bouger");
		mlx_string_put(e->mlx, e->win, 10, 60, 0xF8F8FF,
			"Touche T      : color");
	}
}

void			ft_msg_error(char *msg)
{
	if (msg != NULL)
		ft_putendl(msg);
	else
		ft_putendl("Error");
	exit(1);
}

int				run_hook(t_env *e)
{
	draw_map(e);
	move(e);
	if (e->help == 1)
		display_menu(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	display_menu(e);
	return (0);
}

int				main(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env) * 1)))
		ft_msg_error("Malloc Env Fail");
	if (!(e->mlx = mlx_init()))
		ft_msg_error("MLX INIT FAIL");
	if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3D")))
		ft_msg_error("FAIL WINDOW");
	init_img(e);
	init_env(e);
	mlx_hook(e->win, KEYPRESS, KEYPRESS_MASK, &key_hook, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASE_MASK, &key_press, e);
	mlx_hook(e->win, DESTROY_NOTIFY, DESTROY_MASK, &quit_program, e);
	mlx_loop_hook(e->mlx, &run_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
