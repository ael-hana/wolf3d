/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:52:46 by ael-hana          #+#    #+#             */
/*   Updated: 2016/12/21 08:52:47 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		straffe_left(t_env *e)
{
	if (map((int)(e->wolf->pos_x - e->wolf->plane_x * 0.1),
		(int)(e->wolf->pos_y)) == 0)
		e->wolf->pos_x -= e->wolf->plane_x * 0.1;
	if ((map((int)(e->wolf->pos_x),
		(int)(e->wolf->pos_y - e->wolf->plane_y * 0.1)) == 0))
		e->wolf->pos_y -= e->wolf->plane_y * 0.1;
}

void		straffe_right(t_env *e)
{
	if ((map((int)(e->wolf->pos_x + e->wolf->plane_x * 0.1),
		(int)(e->wolf->pos_y)) == 0))
		e->wolf->pos_x += e->wolf->plane_x * 0.1;
	if ((map((int)(e->wolf->pos_x),
		(int)(e->wolf->pos_y + e->wolf->plane_y * 0.1)) == 0))
		e->wolf->pos_y += e->wolf->plane_y * 0.1;
}
