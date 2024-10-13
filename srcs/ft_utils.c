#include "fdf.h"

float	ft_decimal_part(float num)
{
	if (num > 0.f)
		return (num - (int)num);
	return (num - (int)num + 1.f);
}

float	ft_reciprocal(float num)
{
	return (1.f - ft_decimal_part(num));
}

int	ft_lerp(int v0, int v1, float t)
{
	return ((int)((double)v0 + (v1 - v0) * t));
}
