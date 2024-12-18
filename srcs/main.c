#include "fdf.h"

int			main(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (init_data(argv[1], &data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	free_data(&data);
	ft_mlx_draw(&data);
	ft_mlx_hook(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
