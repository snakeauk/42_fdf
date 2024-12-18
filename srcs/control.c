#include "fdf.h"

int		close_win(void *data);
void	ft_mlx_hook(t_data *data);
void	ft_mlx_reimage(t_data *data);

void	ft_mlx_reimage(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	ft_mlx_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int		close_win(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit (EXIT_SUCCESS);
}

int reset(void *param)
{
	t_data	*data;

	data = (t_data *)param;
    if (!data || !data->map || !data->camera)
        return (EXIT_FAILURE);
	init_map_value(data->map);
	init_camera_value(data->camera);
	ft_mlx_reimage(data);
	return (EXIT_SUCCESS);
}

void	ft_mlx_hook(t_data *data)
{
	mlx_hook(data->win, KEYDOWN, 1L << 0, key_hook, data);
	mlx_hook(data->win, DESTROY, 1L << 5, close_win, data);
}
