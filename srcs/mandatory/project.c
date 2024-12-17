#include "fdf.h"

void draw_line(t_line *line);

static void	isometric(t_point *point, double angle)
{
	double _x;
	double _y;

	_x = point->x;
	_y = point->y;
	point->x = (_x - _y) * cos(angle);
	point->y = (_x + _y) * sin(angle) - point->z;
}

static void cord_isometric(t_line *line)
{
	draw_zoom(&line->start, line->map->scale, line->map->zoom);
	draw_zoom(&line->end, line->map->scale, line->map->zoom);
    rotate(&line->start, line->camera);
	rotate(&line->end, line->camera);
    isometric(&line->start, line->map->angle);
    isometric(&line->end, line->map->angle);
}

void draw_line(t_line *line)
{
	t_point	*start;
	t_point	*end;
	double	delta[2];
    int   	max;

    if (!line)
    {
        ft_dprintf(STDERR_FILENO, "Error: Null pointer in draw_line\n");
        return ;
    }
	start = &line->start;
	end = &line->end;
	cord_isometric(line);
    delta[X] = end->x - start->x;
    delta[Y] = end->y - start->y;
    max = ft_max(ft_abs(delta[X]), ft_abs(delta[Y]));
    delta[X] /= max;
    delta[Y] /= max;
	while ((int)(start->x - end->x) || (int)(start->y - end->y))
    {
        ft_mlx_pixel_put(line->data, (int)start->x + line->camera->x_angle, (int)start->y + line->camera->y_angle, line->color);
        start->x += delta[X];
        start->y += delta[Y];
    }
}
