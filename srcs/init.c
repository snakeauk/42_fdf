#include "test.h"

t_data		*init_data(char	*title)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (free_data(data));
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	return (data);
}
