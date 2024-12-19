#include "fdf.h"

void	draw_zoom(t_point *point, double scale, int zoom)
{
    point->x *= zoom;
    point->y *= zoom;
    point->z *= (int)(scale * (double)zoom);
}
