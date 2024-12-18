#include "fdf.h"

int	init_table(char *filename, t_map *map);

static int full_point(char *line, t_point *point, t_map *map)
{
    char **s;

	s = ft_split(line, ',');
    if (!s)
        return (EXIT_FAILURE);
    point->z = ft_atoi(s[0]);
    if (s[1])
        point->color = ft_strtol(s[1], NULL, 16);
    else
    {
        if (point->z == 0)
            point->color = color_create_trgb(0, 255, 255, 255);
        else
            point->color = color_create_trgb(0, 255, 0, 255);
    }
    ft_free_array2((void **)s);
    return (EXIT_SUCCESS);
}

static t_point **full_array(char *line, t_map *map)
{
    t_point **point;
    char **s;

    point = (t_point **)malloc(sizeof(t_point *) * (map->width + 1));
    if (!point)
        return (NULL);
    s = ft_split(line, ' ');
    if (!s)
    {
        ft_free_array2((void **)point);
        return (NULL);
    }
    map->x = 0;
    while (map->x < map->width)
    {
        point[map->x] = malloc(sizeof(t_point));
        if (!point[map->x])
        {
            ft_free_array2((void **)point);
            ft_free_array2((void **)s);
            return (NULL);
        }
        if (full_point(s[map->x], point[map->x], map) != EXIT_SUCCESS)
        {
            ft_free_array2((void **)point);
            ft_free_array2((void **)s);
            return (NULL);
        }
        map->x++;
    }
    point[map->x] = NULL;
    ft_free_array2((void **)s);
    return point;
}

static int full_table(int fd, t_map *map)
{
    char *line;

    map->table = (t_point ***)malloc(sizeof(t_point **) * (map->height + 1));
    if (!map->table)
        return (EXIT_FAILURE);
    map->y = 0;
    while (get_next_line(fd, &line) > 0)
    {
        map->table[map->y] = full_array(line, map);
        free(line);
        if (!map->table[map->y])
        {
            free_map(&map);
            return (EXIT_FAILURE);
        }
        map->y++;
    }
    map->table[map->y] = NULL;
    return (EXIT_SUCCESS);
}


static int get_size(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	
	fd = ft_fopen(filename, "r");
	if (fd < 0)
		return (EXIT_FAILURE);
	map->height = 0;
	while (get_next_line(fd, &line))
	{
        if (map->height == 0)
		    map->width = get_width(line);
		map->height++;
		free(line);
	}
	if (ft_close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_table(char *filename, t_map *map)
{
	int	fd;
	int	status;

	if (check_file(filename) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (get_size(filename, map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	fd = ft_fopen(filename, "r");
	if (fd < 0)
		return (EXIT_FAILURE);
	status = full_table(fd, map);
	if (ft_close(fd) < 0)
		return (EXIT_FAILURE);
	debug_print_table(map);
	return (EXIT_SUCCESS);
}
