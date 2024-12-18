#include "fdf.h"

void	free_data(t_data *data);
void	free_table(t_point ***table);
void	free_map(t_map **map);


void	free_data(t_data *data)
{
	if (data->map)
		free_map(&data->map);
}

void free_map(t_map **map)
{
    int x;
	int	y;

    if (!map || !*map)
        return;
    if ((*map)->table != NULL)
		free_table((*map)->table);
    free(*map);
    *map = NULL;
}

void	free_table(t_point ***table)
{
	int	x;
	int	y;

    if (table)
    {
		y = 0;
		while (table[y])
		{
			x = 0;
			while(table[y][x])
			{
				free(table[y][x]);
				x++;
			}
			free(table[y]);
			y++;
		}
        free(table);
        table = NULL;
    }
}
