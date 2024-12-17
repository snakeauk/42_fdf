#include "fdf.h"

int	check_file(char *filename);

static int	check_width(char *line)
{
	int		width;
	char	**s;

	width = 0;
	if (!line)
		return (width);
	s = ft_split(line, ' ');
	while (s[width])
	{
		if (ft_atoi(s[width]) == 0 && s[width][0] != '0')
		{
			ft_free_array2((void **)s);
			return (0);
		}
		width++;
	}
	ft_free_array2((void **)s);
	return (width);
}

static int	check_size(int fd)
{
	char	*line;
	int		w;
	int		width;
	int		height;

	height = 0;
	while (get_next_line(fd, &line) != 0)
	{
		w = check_width(line);
		free(line);
		height++;	
		if (height == 1)
			width = w;
		else if (w != width)
		{
			ft_dprintf(STDERR_FILENO, "Error: invalid map width\n");
			return (EXIT_FAILURE);
		}
	}
	if (height == 0)
	{
		ft_dprintf(STDERR_FILENO, "Error: invalid map height\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_file(char *filename)
{
	int		fd;
	int		status;

	if (!filename)
	{
		ft_dprintf(STDERR_FILENO, "Error: filename is null\n");
		return (EXIT_FAILURE);
	}
	fd = ft_fopen(filename, "r");
	if (fd < 0)
		return (EXIT_FAILURE);
	status = check_size(fd);
	if (ft_close(fd) < 0)
		return (EXIT_FAILURE);
	if (status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
