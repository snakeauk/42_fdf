#include "fdf.h"

int	init_data(char *title, t_data *data);

static int	is_file(char *filename)
{
	int		fd;
	char	*line;

	if (!filename)
		return (EXIT_FAILURE);
	fd = ft_fopen(filename, "r");
	if (fd <= 0)
		return (EXIT_FAILURE);
	if (get_next_line(fd, &line) == 0)
	{
		ft_dprintf(STDERR_FILENO, "Error: %s: invalid filename\n", filename);
		return (EXIT_FAILURE);
	}
	free(line);
	while (get_next_line(fd, &line) != 0)
		free(line);
	if (ft_close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	init_data_value(t_data *data)
{
	data->map = NULL;
	data->camera = NULL;
	data->line = NULL;
}

int	init_line(t_line **line, t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	*line = (t_line *)malloc(sizeof(t_line));
	if (!*line)
		return (EXIT_FAILURE);
	(*line)->start = NULL;
	(*line)->end = NULL;
	(*line)->map = data->map;
	(*line)->camera = data->camera;
	(*line)->data = data;
	(*line)->start = (t_point *)malloc(sizeof(t_point));
	if (!(*line)->start)
		return (EXIT_FAILURE);
	(*line)->end = (t_point *)malloc(sizeof(t_point));
	if (!(*line)->end)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_data(char *title, t_data *data)
{
	init_data_value(data);
	if (is_file(title) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_map(title, &(data->map)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_camera(&(data->camera)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_line(&(data->line), data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	data->line_length = data->map->width;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (EXIT_SUCCESS);
}
