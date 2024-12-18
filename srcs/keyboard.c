#include "fdf.h"

int move_angle(int key_code, void *param);
int change_scale(int key_code, void *param);
int	zoom(int key_code, void *param);
int	toggle(int key_code, void *param);
int	key_hook(int key_code, void *param);

int move_angle(int key_code, void *param)
{
	t_data	*data;

	data = (t_data *)param;
    if (!data || !data->camera)
        return (EXIT_FAILURE);
	if (key_code == XK_h)
		data->camera->x_offset -= 10;
	else if (key_code == XK_j)
		data->camera->y_offset += 10;
	else if (key_code == XK_k)
		data->camera->y_offset -= 10;
	else if (key_code == XK_l)
		data->camera->x_offset += 10;
	data->camera->x_angle = data->camera->x_base + data->camera->x_offset;
	data->camera->y_angle = data->camera->y_base + data->camera->y_offset;
	ft_mlx_reimage(data);
	return (EXIT_SUCCESS);
}

int change_scale(int key_code, void *param)
{
	t_data	*data;
	t_map	*map;

	data = (t_data *)param;
    if (!data || !data->map)
        return (EXIT_FAILURE);
	map = data->map;
	if (key_code == XK_minus)
		map->scale_offset -= 0.1;
	else if (key_code == XK_equal)
		map->scale_offset += 0.1;
	if (map->scale_offset < -0.9)
		map->scale_offset = -0.9;
	map->scale = map->scale_base + map->scale_offset;
	ft_mlx_reimage(data);
	return (EXIT_SUCCESS);
}


int	toggle(int key_code, void *param)
{
	t_data	*data;

	data = (t_data *)param;
    if (!data || !data->map)
        return (EXIT_FAILURE);
	if (key_code == XK_Right)
		data->map->rot_x += 0.1;
	else if (key_code == XK_Up)
		data->map->rot_y += 0.1;
	else if (key_code == XK_Left)
		data->map->rot_z += 0.1;
	ft_mlx_reimage(data);
	return (EXIT_SUCCESS);
}

int	zoom(int key_code, void *param)
{
	t_data	*data;
	t_map	*map;

	data = (t_data *)param;
    if (!data || !data->map)
        return (EXIT_FAILURE);
	map = data->map;
	if (key_code == XK_m)
		map->zoom -= 1;
	else if (key_code == XK_p)
		map->zoom += 1;
	if (map->zoom < 0)
		map->zoom = 1;
	ft_mlx_reimage(data);
	return (EXIT_SUCCESS);
}

int	key_hook(int key_code, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key_code == XK_Escape)
		close_win(data);
	else if (key_code == XK_r)
		reset(data);
	else if (key_code == XK_h || key_code == XK_j || key_code == XK_k || key_code == XK_l)
		move_angle(key_code, param);
	else if (key_code == XK_equal || key_code == XK_minus)
		change_scale(key_code, data);
	else if (key_code == XK_m || key_code == XK_p)
		zoom(key_code, data);
	else if (key_code == XK_Right || key_code == XK_Left || key_code == XK_Up)
		toggle(key_code, data);
	return (EXIT_SUCCESS);
}
