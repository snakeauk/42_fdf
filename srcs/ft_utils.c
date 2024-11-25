#include "fdf.h"

double	ft_decimal_part(double num)
{
	if (num > 0.f)
		return (num - (int)num);
	return (num - (int)num + 1.f);
}

double	ft_reciprocal(double num)
{
	return (1.f - ft_decimal_part(num));
}

int	ft_lerp(int v0, int v1, double t)
{
	return ((int)((double)v0 + (v1 - v0) * t));
}
