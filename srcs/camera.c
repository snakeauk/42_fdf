#include "fdf.h"

int		init_camera(t_camera **camera);
void	init_camera_value(t_camera *camera);

int		init_camera(t_camera **camera)
{
	*camera = (t_camera *)malloc(sizeof(t_camera));
	if (!*camera)
	{
		perror("Error: camera");
		return (EXIT_FAILURE);
	}
	init_camera_value(*camera);
	return (EXIT_SUCCESS);
}

void	init_camera_value(t_camera *camera)
{
	camera->x_base = WIDTH / 2;
	camera->y_base = HEIGHT / 2;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->x_angle = camera->x_base + camera->x_offset;
	camera->y_angle = camera->y_base + camera->y_offset;
}
