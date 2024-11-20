#include "test.h"

int	mousedown_hook(int button, int x, int y, void *param);
int	mouseup_hook(int button, int x, int y, void *param);
int	mousemove_hook(int x, int y, void *param);

int	mousedown_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int	mouseup_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}


int	mousemove_hook(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	return (0);
}
