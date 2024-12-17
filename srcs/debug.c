#include "fdf.h"

int	debug_print_table(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			printf("%3d", (map->table[map->y][map->x]->z));
			map->x++;
			if (map->x < map->width)
				printf(", ");
		}
		printf("\n");
		map->y++;
	}
	return (0);
}
