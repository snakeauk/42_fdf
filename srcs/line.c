#include "fdf.h"

void	ft_draw_line(t_point start, t_point end, t_fdf *fdf)
{
	double	dx;
	double	dy;
	double	gradient;

	fdf->steep = ft_abs(end.y - start.y) > ft_abs(end.x - start.x);
	if (fdf->steep)
	{
		ft_swap(&start.x, &start.y);
		ft_swap(&end.x, &end.y);
	}
	if (start.x > end.x)
	{
		ft_swap(&start.x, &end.x);
		ft_swap(&start.y, &end.y);
		start.reverse = 1;
	}
	dx = (double)(end.x - start.x);
	dy = (double)(end.y - start.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(start, end, gradient, fdf);
}
void	ft_draw_line_loop(t_point start, t_point end, double gradient, t_fdf *fdf)
{
	int		x;
	double	y;

	y = (double)start.y;
	x = start.x;
	while (x <= end.x)
	{
		if (fdf->steep)
		{
			ft_draw_pixel(fdf, (int)(y), x, ft_draw_color(x, start, end, ft_reciprocal(y)));
			ft_draw_pixel(fdf, (int)(y) + 1, x, ft_draw_color(x, start, end, ft_decimal_part(y)));
		}
		else
		{
			ft_draw_pixel(fdf, x, (int)(y), ft_draw_color(x, start, end, ft_reciprocal(y)));
			ft_draw_pixel(fdf, x, (int)(y) + 1, ft_draw_color(x, start, end, ft_decimal_part(y)));
		}
		y += gradient;
		x++;
	}
}
