#include "test.h"

t_data		*free_data(t_data *data);
int			main(void);

t_data		*free_data(t_data *data)
{
	if (data->img)
		free(data->img);
	free(data);
	return (NULL);
}

int		main(void)
{
	t_data	*data;

	data = init_data("test mlx");
	if (!data)
		return (EXIT_FAILURE);
	ft_mlx_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	ft_mlx_hook(data);
	mlx_loop(data->mlx);
}
