#include "fdf.h"

int	init_data(char *title, t_data *data);

int	init_data(char *title, t_data *data)
{
	if (init_map(title, data->map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
