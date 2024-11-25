#include "fdf.h"

int	create_color(int t, int r, int g, int b);
int	get_color_t(int t);
int	get_color_r(int r);
int	get_color_g(int g);
int	get_color_b(int b);

int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color_t(int t)
{
	return ((t >> 24) & 0xFF);
}

int	get_color_r(int r)
{
	return ((r >> 16) & 0xFF);
}

int	get_color_g(int g)
{
	return ((g >> 8) & 0xFF);
}

int	get_color_b(int b)
{
	return (b & 0xFF);
}
