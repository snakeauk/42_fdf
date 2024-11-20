#include "fdf.h"

t_data		*free_data(t_data *data);
int			main(int argc, char **argv);

t_data		*free_data(t_data *data)
{
	if (data->img)
		free(data->img);
	free(data);
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_exit_message(EXIT_SUCCESS, "Usage: ./fdf <filename>");
	data = init_data(argv[1]);
	if (!data)
		return (EXIT_FAILURE);
	ft_mlx_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	ft_mlx_hook(data);
	mlx_loop(data->mlx);
}
