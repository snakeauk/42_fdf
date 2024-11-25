#include "fdf.h"

void ft_hook_control(t_fdf *fdf)
{
    mlx_hook(fdf->win, 2, 1L<<0, ft_key_press, fdf);
    mlx_hook(fdf->win, 4, 1L<<2, ft_mouse_down, fdf);
    mlx_hook(fdf->win, 5, 1L<<9, ft_mouse_up, fdf);
    mlx_hook(fdf->win, 6, 1L<<13, ft_mouse_move, fdf);
    mlx_hook(fdf->win, 17, 1L<<0, ft_close_win, fdf);
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
    while (angle > M_PI)
        angle -= 2 * M_PI;
    while (angle < -M_PI)
        angle += 2 * M_PI;
    return (angle);
}
