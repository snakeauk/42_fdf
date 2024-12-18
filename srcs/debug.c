#include "fdf.h"

int	debug_print_table(t_map *map)
{
	int	count;

	count = 0;
	if (!map)
		return (-1);
	map->y = 0;
	ft_printf("width:%d\theight:%d\n", map->width, map->height);
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			ft_printf("%d", (map->table[map->y][map->x]->z));
			count++;
			map->x++;
			if (map->x < map->width)
				ft_printf(", ");
		}
		ft_printf("\n");
		map->y++;
	}
	return (count);
}

int	debug_print_color(t_map *map)
{
	int	count;

	count = 0;
	if (!map)
		return (-1);
	map->y = 0;
	ft_printf("width:%d\theight:%d\n", map->width, map->height);
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			ft_printf("%d", (map->table[map->y][map->x]->color));
			count++;
			map->x++;
			if (map->x < map->width)
				ft_printf(", ");
		}
		ft_printf("\n");
		map->y++;
	}
	return (count);
}
