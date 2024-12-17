#ifndef	FDF_H
# define FDF_H

#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "keysys.h"
#include "errno.h"
#include "math.h"

#define X 0
#define Y 1
#define Z 2

# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17

# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define FT_PI	3.141592653589793238462643

typedef struct s_point
{
	int				color;
	int				x;
	int				y;
	unsigned int	z;
}			t_point;

typedef struct s_camera
{
	int		x_angle;
	int		y_angle;
	int		x_base;
	int		y_base;
	int		x_offset;
	int		y_offset;
}				t_camera;

typedef struct	s_map
{
	t_point	***table;
	int		width;
	int		height;
	int		x;
	int		y;
	int		zoom;
	double	angle;
	double	scale;
	double	scale_base;
	double	scale_offset;
	double	rot_x;
	double	rot_y;
	double	rot_z;
}				t_map;

typedef struct	s_button
{
	int		key_code;
	int		pre_x;
	int		pre_y;
}				t_button;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_camera	*camera;
	t_button	*button;
}				t_data;

typedef	struct s_line
{
	t_point		*start;
	t_point		*end;
	t_map		*map;
	t_camera	*camera;
	t_data		*data;
}				t_line;

// main.c
int			main(int argc, char **argv);

// data.c
int			init_data(char *title, t_data *data);

// map.c
int	init_map(char *filename, t_map *map);
int	get_width(char *line);

// check_file.c
int	check_file(char *filename);


// free.c
void	free_data(t_data *data);
void	free_table(t_point ***table);
void	free_map(t_map **map);

// init_table.c
int	init_table(char *filename, t_map *map);

// color.c
int color_create_trgb(int t, int r, int g, int b);
int	color_get_t(int trgb);
int	color_get_r(int trgb);
int	color_get_g(int trgb);
int	color_get_b(int trgb);

// debug.c
int	debug_print_table(t_map *map);

#endif