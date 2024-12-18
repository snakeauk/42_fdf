#include "fdf.h"

void	init_map_value(t_map *map);
int		get_width(char *line);
int	init_map(char *filename, t_map **map);


void	init_map_value(t_map *map)
{
	map->zoom = 10;
	map->angle = 0.5;
	map->scale_base = 1.0;
	map->scale_offset = 0.0;
	map->scale = map->scale_base + map->scale_offset;
	map->rot_x = 0.0;
	map->rot_y = 0.0;
	map->rot_z = 0.0;
}

int	get_width(char *line)
{
	int		width;
	char	**s;

	width = 0;
	if (!line)
		return (width);
	s = ft_split(line, ' ');
	if (!s)
		return (width);
	while (s[width] != NULL)
		width++;
	ft_free_array2((void **)s);
	return (width);
}

int	init_map(char *filename, t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	(*map)->table = NULL;
	init_map_value(*map);
	if (init_table(filename, *map) != EXIT_SUCCESS)
	{
		free_map(map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
