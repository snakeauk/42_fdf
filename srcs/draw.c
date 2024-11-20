#include "test.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_mlx_draw(t_data *data);

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_mlx_draw(t_data *data)
{
	for (int x = 10; x < 1000; x++)
	{
		for (int y = 10; y < 100; y++)
		{
			if (x <= 100)
				ft_mlx_pixel_put(data->img, x, y, color_create_trgb(0, 255, 0, 0));
			else if (x <= 200)
				ft_mlx_pixel_put(data->img, x, y, color_create_trgb(0, 0, 255, 0));
			else if (x <= 300)
				ft_mlx_pixel_put(data->img, x, y, color_create_trgb(0, 0, 0, 255));
			else if (x <= 400)
				ft_mlx_pixel_put(data->img, x, y, color_create_trgb(0, 255, 255, 0));
			else
				ft_mlx_pixel_put(data->img, x, y, color_create_trgb(0, 255, 0, 255));
		}
	}
}
