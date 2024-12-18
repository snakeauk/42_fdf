#include "fdf.h"

int	init_data(char *title, t_data *data);

int	is_file(char *filename)
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

int	init_data(char *title, t_data *data)
{
	int	fd;

	if (is_file(title) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_map(title, &(data->map)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
