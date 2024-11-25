#include "fdf.h"

void ft_zoom(int button, t_fdf *fdf)
{
    if (button == MOUSE_WHEEL_UP && fdf->camera->zoom != INT_MAX)
        fdf->camera->zoom++;
    else if (button == MOUSE_WHEEL_DOWN && fdf->camera->zoom > 1)
        fdf->camera->zoom--;
    if (fdf->camera->zoom < 1)
        fdf->camera->zoom = 1;
    ft_draw(fdf->map, fdf);
}

int		ft_mouse_down(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
		ft_zoom(button, fdf);
	else if (button == MOUSE_CLICK_LEFT || button == MOUSE_CLICK_RIGHT || button == MOUSE_CLICK_MIDDLE)
	{
		fdf->mouse->button = button;
		fdf->mouse->prev_x = x;
		fdf->mouse->prev_y = y;
	}
	return (0);
}

int	ft_mouse_up(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_CLICK_LEFT || button == MOUSE_CLICK_MIDDLE ||button == MOUSE_CLICK_RIGHT)
		fdf->mouse->button = 0;
	return (0);
}

void ft_mouse_move_z(int x, int y, t_fdf *fdf)
{
    int dy;

    dy = y - fdf->mouse->prev_y;
    if (dy == 0)
        return;
    if (x < (WIDTH / 2) + fdf->camera->x_offset)
        fdf->camera->z_angle -= dy * 0.002;
    else
        fdf->camera->z_angle += dy * 0.002;
    fdf->camera->z_angle = ft_reset_angle(fdf->camera->z_angle);
    fdf->mouse->prev_x = x;
    fdf->mouse->prev_y = y;
}

int	ft_mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mouse->button == MOUSE_CLICK_RIGHT)
	{
		fdf->camera->x_angle += (y - fdf->mouse->prev_y) * 0.002;
		fdf->camera->y_angle += (x - fdf->mouse->prev_x) * 0.002;
		fdf->camera->x_angle = ft_reset_angle(fdf->camera->x_angle);
		fdf->camera->y_angle = ft_reset_angle(fdf->camera->y_angle);
		fdf->mouse->prev_x = x;
		fdf->mouse->prev_y = y;
	}
	else if (fdf->mouse->button == MOUSE_CLICK_LEFT)
	{
		fdf->camera->x_offset += (x - fdf->mouse->prev_x);
		fdf->camera->y_offset += (y - fdf->mouse->prev_y);
		fdf->mouse->prev_x = x;
		fdf->mouse->prev_y = y;
	}
	else if (fdf->mouse->button == MOUSE_CLICK_MIDDLE)
		ft_mouse_move_z(x, y, fdf);
	ft_draw(fdf->map, fdf);
	return (0);
}
