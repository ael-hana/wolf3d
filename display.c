/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:52:24 by ael-hana          #+#    #+#             */
/*   Updated: 2016/12/21 08:52:25 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		pixel_put_to_image(t_env *e, double x, double y, int color)
{
	int		pos;

	pos = (((int)y * e->img.sline) + ((int)x * (e->img.bpp / 8)));
	if (e->img.endian)
	{
		e->img.data[pos] = (color & 0xFF0000) >> 16;
		e->img.data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img.data[pos + 2] = (color & 0x0000FF);
	}
	else
	{
		e->img.data[pos] = (color & 0x0000FF);
		e->img.data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img.data[pos + 2] = (color & 0xFF0000) >> 16;
	}
}

void		draw_sky(t_env *e, int x, int end)
{
	int		y;

	y = end;
	while (y < HEIGHT)
	{
		pixel_put_to_image(e, x, HEIGHT - y - 1, 0xCFECF2);
		pixel_put_to_image(e, x, y, 0xCCAAFF);
		y++;
	}
}

int			draw_y(t_env *e, double x, int start, int end)
{
	int		y;

	y = start;
	while (y < end)
	{
		pixel_put_to_image(e, x, y, e->color);
		y++;
	}
	draw_sky(e, x, end);
	return (1);
}
