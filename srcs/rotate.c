#include "fdf.h"

void 	rotate_x(int *y, int *z, double angle);
void 	rotate_y(int *x, int *z, double angle);
void 	rotate_z(int *x, int *y, double angle);
void    rotate(t_point *point, t_map *map);

void rotate_x(int *y, int *z, double angle)
{
    int _y;
    
    _y = *y;
    *y = (int)((double)_y * cos(angle) - (double)(*z) * sin(angle));
    *z = (int)((double)_y * sin(angle) + (double)(*z) * cos(angle));
}

void rotate_y(int *x, int *z, double angle)
{
    int _x;

    _x = *x;
    *x = (int)((double)_x * cos(angle) + (double)(*z) * sin(angle));
    *z = (int)((double)(-_x) * sin(angle) + (double)(*z) * cos(angle));
}

void rotate_z(int *x, int *y, double angle)
{
    int _x;
    
    _x = *x;
    *x = (int)((double)_x * cos(angle) - (double)(*y) * sin(angle));
    *y = (int)((double)_x * sin(angle) + (double)(*y) * cos(angle));
}

void    rotate(t_point *point, t_map *map)
{
    rotate_x(&point->y, &point->z, map->rot_x);
    rotate_y(&point->x, &point->z, map->rot_y);
    rotate_z(&point->x, &point->y, map->rot_z);
}
