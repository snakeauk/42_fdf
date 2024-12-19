#include "fdf.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_mlx_draw(t_data *data);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void init_line_horizontal(t_line **line)
{
	(*line)->start->x = (*line)->map->x;
	(*line)->start->y = (*line)->map->y;
	(*line)->end->x = (*line)->start->x + 1;
	(*line)->end->y = (*line)->start->y;
	(*line)->start->z = (*line)->map->table[(int)(*line)->start->y][(int)(*line)->start->x]->z;
	(*line)->end->z = (*line)->map->table[(int)(*line)->end->y][(int)(*line)->end->x]->z;
	(*line)->color = (*line)->map->table[(int)(*line)->end->y][(int)(*line)->end->x]->color;
}

static void init_line_vertical(t_line **line)
{
	(*line)->start->x = (*line)->map->x;
	(*line)->start->y = (*line)->map->y;
	(*line)->end->x = (*line)->start->x;
	(*line)->end->y = (*line)->start->y + 1;
	(*line)->start->z = (*line)->map->table[(int)(*line)->start->y][(int)(*line)->start->x]->z;
	(*line)->end->z = (*line)->map->table[(int)(*line)->end->y][(int)(*line)->end->x]->z;
	(*line)->color = (*line)->map->table[(int)(*line)->end->y][(int)(*line)->end->x]->color;
}

static void	draw_line_loop(t_line *line)
{
	if (!line->map)
		return ;
	line->map->y = 0;
	while (line->map->y < line->map->height)
	{
		line->map->x = 0;
		while (line->map->x < line->map->width)
		{
			// printf("[%d, %d]\n", line->map->x, line->map->y);
			if (line->map->x < line->map->width - 1)
			{
				init_line_horizontal(&line);
				draw_line(line);
			}
			if (line->map->y < line->map->height - 1)
			{
				init_line_vertical(&line);
				draw_line(line);
			}
			line->map->x++;
		}
		line->map->y++;
	}
}


void	ft_mlx_draw(t_data *data)
{
	t_line	*line;

	line = data->line;
	draw_line_loop(line);
}
