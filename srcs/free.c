#include "fdf.h"

void	free_data(t_data *data);
void	free_line(t_line *line);
void	free_table(t_point ***table);
void	free_map(t_map *map);


void	free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->map != NULL)
		{
			free_map(data->map);
			data->map = NULL;
		}
		if (data->camera != NULL)
		{
			free(data->camera);
			data->camera = NULL;
		}
		if (data->line != NULL)
		{
			free_line(data->line);
			data->line = NULL;
		}
		data = NULL;
	}
}

void	free_line(t_line *line)
{
	if (line != NULL)
	{
		if (line->start != NULL)
		{
			free(line->start);
			line->start = NULL;
		}
		if (line->end != NULL)
		{
			free(line->end);
			line->end = NULL;
		}
		line->map = NULL;
		line->camera = NULL;
		line->data = NULL;
		free(line);
		line = NULL;
	}
}

void free_map(t_map *map)
{
    int x;
	int	y;

    if (!map)
        return;
    if (map->table != NULL)
		free_table(map->table);
    free(map);
    map = NULL;
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
