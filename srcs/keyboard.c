#include "test.h"

int	keyup_hook(int key_code, void *param);
int	key_hook(int key_code, void *param);

int	keyup_hook(int key_code, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)key_code;
	return (0);
}

int	key_hook(int key_code, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key_code == XK_Escape)
		close_win(data);
	return (0);
}
