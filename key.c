/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:52:31 by ael-hana          #+#    #+#             */
/*   Updated: 2016/12/21 08:52:33 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			key_norme(int keycode, t_env *e)
{
	if (keycode == KEY_A)
		straffe_left(e);
	if (keycode == KEY_D)
		straffe_right(e);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_H)
		e->help = (e->help == 1) ? 0 : 1;
	if (keycode == KEY_T)
		e->change = (e->change == 1) ? 0 : 1;
	if (keycode == KEY_UP)
		e->key.up = 1;
	if (keycode == KEY_RIGHT)
		e->key.right = 1;
	if (keycode == KEY_DOWN)
		e->key.down = 1;
	if (keycode == KEY_LEFT)
		e->key.left = 1;
	if (keycode == ECHAP)
		quit_program(e);
	key_norme(keycode, e);
	run_hook(e);
	return (0);
}

int				key_press(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->key.up = 0;
	if (keycode == KEY_RIGHT)
		e->key.right = 0;
	if (keycode == KEY_DOWN)
		e->key.down = 0;
	if (keycode == KEY_LEFT)
		e->key.left = 0;
	run_hook(e);
	return (0);
}
