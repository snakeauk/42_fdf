#include "fdf.h"

void draw_line(t_line *line);

static void	isometric(t_point *point, double angle)
{
	int _x;
	int _y;

	_x = point->x;
	_y = point->y;
	point->x = (int)((double)(_x - _y) * cos(angle));
	point->y = (int)((double)(_x + _y) * sin(angle)) - point->z;
}

static void cord_isometric(t_line *line)
{
	draw_zoom(line->start, line->map->scale, line->map->zoom);
	draw_zoom(line->end, line->map->scale, line->map->zoom);
    rotate(line->start, line->map);
	rotate(line->end, line->map);
    isometric(line->start, line->map->angle);
    isometric(line->end, line->map->angle);
}

void draw_line(t_line *line)
{
	t_point	*start;
	t_point	*end;
	double	dx;
	double	dy;
	double	x;
	double	y;
    int   	max;

    if (!line)
    {
        ft_dprintf(STDERR_FILENO, "Error: Null pointer in draw_line\n");
        return ;
    }
	start = line->start;
	end = line->end;
	cord_isometric(line);
    dx = (double)(end->x - start->x);
    dy = (double)(end->y - start->y);
    max = ft_max(ft_abs(dx), ft_abs(dy));
    dx /= (double)max;
    dy /= (double)max;
	x = (double)start->x;
	y = (double)start->y;
	// printf("[%f, %f] start[%d, %d] end[%d, %d]\n", dx, dy, start->x, start->y, end->x, end->y);
	while ((int)(x - (double)end->x) || (int)(y - (double)end->y))
    {
        ft_mlx_pixel_put(line->data, x + (int)line->camera->x_angle, y + (int)line->camera->y_angle, line->color);
        x += dx;
        y += dy;
    }
}
// void draw_line(t_line *line);

// static void	isometric(t_point *point, double angle)
// {
// 	int _x;
// 	int _y;

// 	_x = point->x;
// 	_y = point->y;
// 	point->x = (int)((double)(_x - _y) * cos(angle));
// 	point->y = (int)((double)(_x + _y) * sin(angle)) - point->z;
// }

// static void cord_isometric(t_line *line)
// {
// 	draw_zoom(line->start, line->map->scale, line->map->zoom);
// 	draw_zoom(line->end, line->map->scale, line->map->zoom);
//     rotate(line->start, line->map);
// 	rotate(line->end, line->map);
//     isometric(line->start, line->map->angle);
//     isometric(line->end, line->map->angle);
// }

// void	bresenham(t_line *line)
// {
// 	double	dx;
// 	double	dy;
// 	int		max;
// 	double	x;
// 	double	y;

// 	x = line->start->x;
// 	y = line->start->y;
// 	dx = (double)(line->end->x - line->start->x);
//     dy = (double)(line->end->y - line->start->y);
//     max = ft_max(ft_abs(dx), ft_abs(dy));
// 	dx /= max;
// 	dy /= max;
// 	while ((int)(x - line->end->x) || (int)(y - line->end->y))
// 	{
// 		ft_mlx_pixel_put(line->data, (int)(x + line->camera->x_angle), (int)(y + line->camera->y_angle), line->color);
// 		x += dx;
// 		y += dy;
// 	}
// }

// void draw_line(t_line *line)
// {
// 	t_point	*start;
// 	t_point	*end;
// 	double	delta[2];
//     int   	max;

//     if (!line)
//     {
//         ft_dprintf(STDERR_FILENO, "Error: Null pointer in draw_line\n");
//         return ;
//     }
// 	start = line->start;
// 	end = line->end;
// 	cord_isometric(line);
// 	bresenham(line);
// }
