#include "fdf.h"

void	ft_hook_control(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, ft_key_press, fdf);
	mlx_hook(fdf->win, 4, 0, ft_mouse_down, fdf);
	mlx_hook(fdf->win, 5, 0, ft_mouse_up, fdf);
	mlx_hook(fdf->win, 6, 0, ft_mouse_move, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close_win, fdf);
}

int		ft_close_win(void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	fdf = (t_fdf *)param;
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->camera);
	free(fdf->mouse);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			free(fdf->map->array[y][x]);
			x++;
		}
		free(fdf->map->array[y]);
		y++;
	}
	free(fdf->map->array);
	free(fdf->map);
	free(fdf->mlx);
	free(fdf);
	exit(EXIT_SUCCESS);
}

double	ft_reset_angle(double angle)
{
	if (angle >= PI)
		return (-2 * PI - angle);
	else if (angle <= -PI)
		return (2 * PI + angle);
	return (angle);
}
