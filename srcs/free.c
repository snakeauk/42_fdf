#include "fdf.h"

void	free_data(t_data *data)
{
	if (data)
		free(data);
}
