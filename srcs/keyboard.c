#include "fdf.h"

void	ft_translate(int key_code, t_fdf *fdf)
{
	if (key_code == XK_h)
		fdf->camera->x_offset -= 10;
	else if (key_code == XK_l)
		fdf->camera->x_offset += 10;
	else if (key_code == XK_k)
		fdf->camera->y_offset -= 10;
	else if (key_code == XK_j)
		fdf->camera->y_offset += 10;
}
void	ft_toggle(t_fdf *fdf)
{
	fdf->camera->z_angle += 0.1;
	fdf->camera->z_angle = ft_reset_angle(fdf->camera->z_angle);
}

void	ft_reset(t_fdf *fdf)
{
	fdf->camera->x_offset = 0;
	fdf->camera->y_offset = 0;
	if (fdf->camera->iso)
	{
		fdf->camera->x_angle = -0.615472907;
		fdf->camera->y_angle = -0.623599;
		fdf->camera->z_angle = 0.615472907;
	}
	else
	{
		fdf->camera->x_angle = -0.523599;
		fdf->camera->y_angle = -0.261799;
		fdf->camera->z_angle = 0;
	}
	fdf->camera->z_height = 1;
	fdf->camera->zoom = ft_min(WIDTH / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);
}

void	ft_height(int key_code, t_fdf *fdf)
{
	if (key_code == XK_equal)
		fdf->camera->z_height -= 0.15;
	else if (key_code == XK_minus)
		fdf->camera->z_height += 0.15;
	if (fdf->camera->z_height < 0.1)
		fdf->camera->z_height = 0.1;
	else if (fdf->camera->z_height > 10)
		fdf->camera->z_height = 10;
}

int	ft_key_press(int key_code, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key_code == XK_Escape)
		ft_close_win(fdf);
	else if (key_code == XK_h || key_code == XK_j || key_code == XK_k || key_code == XK_l)
		ft_translate(key_code, fdf);
	else if (key_code == XK_space)
		ft_toggle(fdf);
	else if (key_code == XK_r)
		ft_reset(fdf);
	else if (key_code == XK_minus || key_code == XK_equal)
		ft_height(key_code, fdf);
	ft_draw(fdf->map, fdf);
	return (0);
}
