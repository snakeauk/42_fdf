#include "fdf.h"

void	ft_init_table(int **array, char *line, int width)
{
	char	**str;
	int		index;
	int		len;

	str = ft_split(line, ' ');
	index = 0;
	while (str[index] && index < width)
	{
		array[index] = (int *)malloc(sizeof(int) * 2);
		if (!array[index])
			ft_exit_message("Error: can't malloc");
		array[index][0] = ft_atoi(str[index]);
		len = 0;
		while (str[index][len] && str[index][len] != ',')
			len++;
		if (str[index][len] == ',')
			array[index][1] = ft_strtol(&str[index][len], NULL, 16);
		else
			array[index][1] = -1;
		free(str[index]);
	}
	if (str[index] || index != width)
		ft_exit_message("Error: iregular width");
	free(str);
}

int		ft_size_width(char *filename)
{
	int		fd;;
	int		width;
	int		index;
	char	*line;

	fd = ft_fopen(filename, "r");
	width = 0;
	index = 0;
	line = get_next_line(fd);
	if (*line == '\0')
		ft_exit_message("Error: invalid map");
	while (line[index])
	{
		if (line[index] != ' ' && (line[index + 1] == ' ' || line[index + 1] == '\0'))
			width++;
		index++;
	}
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		ft_exit_message("Error: can't close");
	return (width);
}

int	ft_size_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = ft_fopen(filename, "r");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close (fd) == -1)
		ft_exit_message("Error: can't close");
	return (height);
}

void	ft_init_z(t_map *map)
{
	int	index;
	int	len;

	index = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (index < map->height)
	{
		len = 0;
		while (len < map->width)
		{
			if (map->array[index][len][0] < map->z_min)
				map->z_min = map->array[index][len][0];
			if (map->array[index][len][0] > map->z_max)
				map->z_max = map->array[index][len][0];
			len++;
		}
		index++;
	}
}

void	ft_check_input(char *filename, t_map *map)
{
	int		fd;;
	int		index;
	char	*line;

	map->width = ft_size_width(filename);
	map->height = ft_size_height(filename);
	fd = ft_fopen(filename, "r");
	index = 0;
	map->array = (int ***)malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_exit_message("Error: can't malloc");
	line = get_next_line(fd);
	while (ft_strlen(line) >= 0 && *line != '\0')
	{
		map->array[index] = (int **)malloc(sizeof(int *) * map->width);
		if (!map->array[index])
			ft_exit_message("Error: can't malloc");
		ft_init_table(map->array[index], line, map->width);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	free(line);
	ft_init_z(map);
	if (close(fd) == -1)
		ft_exit_message("Error: can't close");
}