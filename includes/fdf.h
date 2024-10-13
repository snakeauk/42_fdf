#ifndef	FDF_H
# define FDF_H

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "mlx.h"
#include "math.h"

#define WIDTH 1920
#define HEIGHT 1080

# define MAC_A 0
# define MAC_S 1
# define MAC_D 2
# define MAC_H 4
# define MAC_W 13
# define MAC_R 15
# define MAC_PLUS 24
# define MAC_MINUS 27
# define MAC_L 37
# define MAC_J 38
# define MAC_K 40
# define MAC_SPACE 49
# define MAC_ESCAPE 53

# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define PI 3.1415926535

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int reverse;
}				t_point;

typedef struct s_map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
}				t_map;

typedef struct s_camera
{
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
	int		iso;
}				t_camera;

typedef struct s_mouse
{
	int		button;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
}				t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_mouse		*mouse;
	t_map		*map;
	t_camera	*camera;
}				t_fdf;

int			main(int argc, char **argv);
t_fdf		*ft_fdf_init(char *path);
t_map		*ft_map_init(void);


void		ft_draw(t_map *map, t_fdf *fdf);
void		ft_draw_line(t_point start, t_point end, t_fdf *fdf);
int			ft_draw_color(int x, t_point start,t_point end, float factor);
void		ft_draw_line_loop(t_point start, t_point end, float gradient, t_fdf *fdf);
void		ft_draw_pixel(t_fdf *fdf, int x, int y, int color);
int			ft_draw_default_color(int z, t_map *map);

t_camera	*ft_camera_init(t_fdf *fdf);

void		ft_translate(int key_code, t_fdf *fdf);

void		ft_toggle(t_fdf *fdf);
void		ft_reset(t_fdf *fdf);
void		ft_height(int key_code, t_fdf *fdf);
int			ft_key_press(int key_code, void *param);

void		ft_init_table(int **array, char *line, int width);
int			ft_size_width(char *filename);
int			ft_size_height(char *filename);
void		ft_init_z(t_map *map);
void		ft_check_input(char *filename, t_map *map);

void		ft_hook_control(t_fdf *fdf);
int			ft_close_win(void *param);
double		ft_reset_angle(double angle);

void		ft_zoom(int button, t_fdf *fdf);
int			ft_mouse_down(int button, int x, int y, void *param);
int			ft_mouse_up(int button, int x, int y, void *param);
void		ft_mouse_move_z(int x, int y, t_fdf *env);
int			ft_mouse_move(int x, int y, void *param);


void		ft_rotate_x(int *y, int *z, double x_angle);
void		ft_rotate_y(int *x, int *z, double y_angle);
void		ft_rotate_z(int *x, int *y, double z_angle);
t_point		ft_project(int x, int y, t_fdf *fdf);

float		ft_decimal_part(float num);
float		ft_reciprocal(float num);
int			ft_lerp(int v0, int v1, float t);

#endif