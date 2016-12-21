#include "wolf.h"

void		init_dir(t_dir *key)
{
	key->up = 0;
	key->right = 0;
	key->down = 0;
	key->left = 0;
}

void		init_img(t_env *e)
{
	if (!(e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		ft_msg_error("Err : Creation img");
	if (!(e->img.data = mlx_get_data_addr(e->img.img, &(e->img.bpp),
		&(e->img.sline), &(e->img.endian))))
		ft_msg_error("Err : Get Data");
}

t_w3d		*init_w3d(void)
{
	t_w3d	*w;

	w = (t_w3d*)malloc(sizeof(t_w3d) * 1);
	w->pos_x = 18;
	w->pos_y = 18;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0.0;
	w->plane_y = 0.66;
	return (w);
}

void		init_env(t_env *e)
{
	init_dir(&e->key);
	e->wolf = init_w3d();
	e->help = 0;
	e->change = 0;
}
