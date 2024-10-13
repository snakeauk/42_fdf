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

int	ft_draw_default_color(int z, t_map *map)
{
	double	percent;
	int		max;

	max = map->z_max - map->z_min;
	if (max == 0)
		return (0x432371);
	percent = ((double)(z - map->z_min) / max);
	if (percent < 0.2)
		return (0x432371);
	else if (percent < 0.4)
		return (0x714674);
	else if (percent < 0.6)
		return (0x9F6976);
	else if (percent < 0.8)
		return (0xCC8B79);
	else
		return (0xFAAE7B);
}

int	ft_draw_color(int x, t_point start,t_point end, float factor)
{
	int	r;
	int	g;
	int b;
	float percent;

	percent = ft_abs(x - start.x) / ft_abs(end.x - start.x);
	if (start.reverse)
	{
		r = ft_lerp((end.color >> 16) & 0xFF, (start.color >> 16) & 0xFF, percent);
		g = ft_lerp((end.color >> 8) & 0xFF, (start.color >> 8) & 0xFF, percent);
		b = ft_lerp(end.color & 0xFF, start.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percent);
		g = ft_lerp((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percent);
		b = ft_lerp(start.color & 0xFF, end.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b );
}
