#include "wolf.h"

void		move_up(t_env *e)
{
	if ((map((int)(e->wolf->pos_x + e->wolf->dir_x * 0.05),
		(int)(e->wolf->pos_y)) == 0))
		e->wolf->pos_x += e->wolf->dir_x * 0.05;
	if ((map((int)(e->wolf->pos_x),
		(int)(e->wolf->pos_y + e->wolf->dir_y * 0.05)) == 0))
		e->wolf->pos_y += e->wolf->dir_y * 0.05;
}

void		move_right(t_env *e)
{
	double	olddirx;
	double	oldplanex;

	olddirx = e->wolf->dir_x;
	e->wolf->dir_x = e->wolf->dir_x * cos(-1 * 0.02) - e->wolf->dir_y *
		sin(-1 * 0.02);
	e->wolf->dir_y = olddirx * sin(-1 * 0.02) + e->wolf->dir_y *
		cos(-1 * 0.02);
	oldplanex = e->wolf->plane_x;
	e->wolf->plane_x = e->wolf->plane_x * cos(-1 * 0.02) - e->wolf->plane_y *
		sin(-1 * 0.02);
	e->wolf->plane_y = oldplanex * sin(-1 * 0.02) + e->wolf->plane_y *
		cos(-1 * 0.02);
}

void		move_down(t_env *e)
{
	if ((map((int)(e->wolf->pos_x - e->wolf->dir_x * 0.05),
		(int)(e->wolf->pos_y)) == 0))
		e->wolf->pos_x -= e->wolf->dir_x * 0.05;
	if ((map((int)(e->wolf->pos_x),
		(int)(e->wolf->pos_y - e->wolf->dir_y * 0.05)) == 0))
		e->wolf->pos_y -= e->wolf->dir_y * 0.05;
}

void		move_left(t_env *e)
{
	double	olddirx;
	double	oldplanex;

	olddirx = e->wolf->dir_x;
	e->wolf->dir_x = e->wolf->dir_x * cos(0.02) - e->wolf->dir_y * sin(0.02);
	e->wolf->dir_y = olddirx * sin(0.02) + e->wolf->dir_y * cos(0.02);
	oldplanex = e->wolf->plane_x;
	e->wolf->plane_x = e->wolf->plane_x * cos(0.02) - e->wolf->plane_y * sin(0.02);
	e->wolf->plane_y = oldplanex * sin(0.02) + e->wolf->plane_y * cos(0.02);
}

void		move(t_env *e)
{
	if (e->key.up)
		move_up(e);
	else if (e->key.right)
		move_right(e);
	else if (e->key.down)
		move_down(e);
	else if (e->key.left)
		move_left(e);
}
