#include "fdf.h"

void	ft_draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bpp / 8));
	y = 0;
	if (fdf->camera->x_angle > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
	{
		x = 0;
		if (fdf->camera->y_angle > 0)
			x = map->width - 1;
		while (x >= 0 && x < map->width)
		{
			if (x != map->width - 1)
				ft_draw_line(ft_project(x, y, fdf), ft_project(x + 1, y, fdf), fdf);
			if (y != map->height - 1)
				ft_draw_line(ft_project(x, y, fdf), ft_project(x, y + 1, fdf), fdf);
			x += -2 *(fdf->camera->y_angle > 0) + 1;
		}
		y += -2 * (fdf->camera->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	ft_draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	int index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_addr[index] = color;
		index++;
		fdf->data_addr[index] = color >> 8;
		index++;
		fdf->data_addr[index] = color >> 16;
	}
}
int ft_draw_default_color(int z, t_map *map)
{
    double percent;
    int max;

    max = map->z_max - map->z_min;
    if (max == 0)
        return (0x005F8F);
    percent = ((double)(z - map->z_min) / max);
    if (percent < 0.2)
        return (0x0074A6);
    else if (percent < 0.4)
        return (0x339ACC);
    else if (percent < 0.6)
        return (0x66C2E0);
    else if (percent < 0.8)
        return (0xBFE8F7);
    else
        return (0xFFFFFF);
}


int	ft_draw_color(int x, t_point start, t_point end, double factor)
{
	int		r, g, b;
	double	percent;
	
	
	if (end.x == start.x)
		percent = 1.0;
	else
		percent = ((double)(x - start.x) / (end.x - start.x));
	if (start.reverse)
	{
		r = ft_lerp(get_color_r(end.color), get_color_r(start.color), percent);
		g = ft_lerp(get_color_g(end.color), get_color_g(start.color), percent);
		b = ft_lerp(get_color_b(end.color), get_color_b(start.color), percent);
	}
	else
	{
		r = ft_lerp(get_color_r(start.color), get_color_r(end.color), percent);
		g = ft_lerp(get_color_g(start.color), get_color_g(end.color), percent);
		b = ft_lerp(get_color_b(start.color), get_color_b(end.color), percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return (create_color(1, r, g, b));
}
