#include "fdf.h"

void rotate_x(double *y, double *z, double angle);
void rotate_y(double *x, double *z, double angle);
void rotate_z(double *x, double *y, double angle);
void    rotate(t_point *point, t_camera *camera);

void rotate_x(double *y, double *z, double angle)
{
    double _y;
    
    _y = *y;
    *y = _y * cos(angle) - (*z) * sin(angle);
    *z = _y * sin(angle) + (*z) * cos(angle);
}

void rotate_y(double *x, double *z, double angle)
{
    double _x;
    _x = *x;
    *x = _x * cos(angle) + (*z) * sin(angle);
    *z = -_x * sin(angle) + (*z) * cos(angle);
}

void rotate_z(double *x, double *y, double angle)
{
    double _x;
    
    _x = *x;
    *x = _x * cos(angle) - (*y) * sin(angle);
    *y = _x * sin(angle) + (*y) * cos(angle);
}

void    rotate(t_point *point, t_camera *camera)
{
    rotate_x(&point->y, &point->z, camera->rot_x);
    rotate_y(&point->x, &point->z, camera->rot_y);
    rotate_z(&point->x, &point->y, camera->rot_z);
}