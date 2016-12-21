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
