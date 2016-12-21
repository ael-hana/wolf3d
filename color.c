/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:52:18 by ael-hana          #+#    #+#             */
/*   Updated: 2016/12/21 08:52:20 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		color_1(t_env *e)
{
	if (e->wolf->side == 0)
	{
		if (e->wolf->step_x <= 0)
			e->color = 0xFF0000;
		else
			e->color = 0xCC8B1A;
	}
	else
	{
		if (e->wolf->step_y <= 0)
			e->color = 0x39FF8D;
		else
			e->color = 0xB953FF;
	}
}

void		color_2(t_env *e)
{
	if (e->wolf->side == 0)
	{
		if (e->wolf->step_x <= 0)
			e->color = 0x5AB479;
		else
			e->color = 0x5AB4A6;
	}
	else
	{
		if (e->wolf->step_y <= 0)
			e->color = 0x5A95B4;
		else
			e->color = 0x5A68B4;
	}
}
