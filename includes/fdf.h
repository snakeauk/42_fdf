#ifndef FDF_H
# define FDF_H

# include "errno.h"
# include "ft_printf.h"
# include "keysys.h"
# include "libft.h"
# include "math.h"
# include "mlx.h"

# define X 0
# define Y 1
# define Z 2

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

# define FT_PI 3.141592653589793238462643

typedef struct s_point
{
	int				color;
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct s_camera
{
	int				x_angle;
	int				y_angle;
	int				x_base;
	int				y_base;
	int				x_offset;
	int				y_offset;
}					t_camera;

typedef struct s_map
{
	t_point			***table;
	int				width;
	int				height;
	int				x;
	int				y;
	int				zoom;
	double			angle;
	double			scale;
	double			scale_base;
	double			scale_offset;
	double			rot_x;
	double			rot_y;
	double			rot_z;
}					t_map;

typedef struct s_button
{
	int				key_code;
	int				pre_x;
	int				pre_y;
}					t_button;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_map			*map;
	t_camera		*camera;
}					t_data;

typedef struct s_line
{
	int				color;
	t_point			*start;
	t_point			*end;
	t_map			*map;
	t_camera		*camera;
	t_data			*data;
}					t_line;

// project.c
void draw_line(t_line *line);


// main.c
int					main(int argc, char **argv);

// data.c
int					init_data(char *title, t_data *data);

// map.c
void				init_map_value(t_map *map);
int					get_width(char *line);
int					init_map(char *filename, t_map **map);


// check_file.c
int					check_file(char *filename);

// free.c
void				free_data(t_data *data);
void				free_table(t_point ***table);
void				free_map(t_map *map);

// init_table.c
int					init_table(char *filename, t_map *map);

// camera.c
int					init_camera(t_camera **camera);
void				init_camera_value(t_camera *camera);

// draw.c
void				ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_mlx_draw(t_data *data);

// control.c
int					close_win(void *data);
void				ft_mlx_hook(t_data *data);
void				ft_mlx_reimage(t_data *data);
int					reset(void *param);

// keyboard.c
int					move_angle(int key_code, void *param);
int					change_scale(int key_code, void *param);
int					zoom(int key_code, void *param);
int					toggle(int key_code, void *param);
int					key_hook(int key_code, void *param);

// color.c
int					color_create_trgb(int t, int r, int g, int b);
int					color_get_t(int trgb);
int					color_get_r(int trgb);
int					color_get_g(int trgb);
int					color_get_b(int trgb);

// zoom.c
void				draw_zoom(t_point *point, double scale, int zoom);

// rotate.c
void 				rotate_x(int *y, int *z, double angle);
void 				rotate_y(int *x, int *z, double angle);
void 				rotate_z(int *x, int *y, double angle);
void				rotate(t_point *point, t_map *map);

// debug.c
int					debug_print_table(t_map *map);
int					debug_print_color(t_map *map);

#endif