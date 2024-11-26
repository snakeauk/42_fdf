#include "fdf.h"

t_fdf	*ft_fdf_init(char *path)
{
	t_fdf	*fdf;
	char	*title;

	title = ft_strjoin("FDF - ", path);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		ft_exit_message(EXIT_FAILURE, "Error: malloc fdf");
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_exit_message(EXIT_FAILURE, "Error: Connecting to graphics server");
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, title);
	if (!fdf->win)
		ft_exit_message(EXIT_FAILURE, "Error: initializing window");
	free(title);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_exit_message(EXIT_FAILURE, "Error: initializing image");
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line, &fdf->endian);
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		ft_exit_message(EXIT_FAILURE, "Error: initializing mouse");
	fdf->map = NULL;
	fdf->camera = NULL;
	return (fdf);
}

t_map	*ft_map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_exit_message(EXIT_FAILURE, "Error: malloc map\n");
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

t_camera	*ft_camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_exit_message(EXIT_FAILURE, "Error: initializing camera\n");
	camera->zoom = ft_min(WIDTH / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);
	camera->x_angle = -0.5;
	camera->y_angle = -0.5;
	camera->z_angle = 0.5;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}
int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_exit_message(EXIT_FAILURE, "Usage: ./fdf <filename>\n");
	fdf = ft_fdf_init(argv[1]);
	fdf->map = ft_map_init();
	ft_check_input(argv[1], fdf->map);
	fdf->camera = ft_camera_init(fdf);
	ft_hook_control(fdf);
	ft_draw(fdf->map, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
