#include "test.h"

int		close_win(void *data);
void	ft_mlx_hook(t_data *data);

int		close_win(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit (EXIT_SUCCESS);
}

void	ft_mlx_hook(t_data *data)
{
	mlx_hook(data->win, KEYDOWN, 1L<<0, key_hook, data);
	// mlx_hook(data->win, KEYUP, 1, key_hook, data);
	mlx_hook(data->win, MOUSEDOWN, 1, mousedown_hook, data);
	mlx_hook(data->win, MOUSEUP, 1, mouseup_hook, data);
	mlx_hook(data->win, MOUSEMOVE, 1, mousemove_hook, data);
	// mlx_hook(data->win, EXPOSE, 1, key_hook, data);
	mlx_hook(data->win, DESTROY, 1, close_win, data);
}
