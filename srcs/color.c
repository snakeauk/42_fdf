#include "test.h"

int color_create_trgb(int t, int r, int g, int b);
int	color_get_t(int trgb);
int	color_get_r(int trgb);
int	color_get_g(int trgb);
int	color_get_b(int trgb);

int color_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_get_t(int t)
{
	return ((t >> 24) & 0xFF);
}

int	color_get_r(int r)
{
	return ((r >> 16) & 0xFF);
}

int	color_get_g(int g)
{
	return ((g >> 8) & 0xFF);
}

int	color_get_b(int b)
{
	return (b & 0xFF);
}
