/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:57:34 by mchi              #+#    #+#             */
/*   Updated: 2019/03/15 11:45:04 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define PI 3.14159265359
# define MAGENTA 0x00FF00

# define X 0
# define Y 1
# define Z 2

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

# include <mlx.h>
# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>

typedef unsigned int	t_uint;

typedef struct	s_coord
{
	double	r;
	double	i;
}				t_coord;

typedef struct	s_img
{
	char	*ptr;
	char	*data_addr;
	int		sl;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_wnd
{
	void			*wnd_handle;
	struct s_app	*app;
	t_uint			width;
	t_uint			height;
	t_img			img;
	char			*name;
	int				wnd_id;
	t_coord			min;
	double			step;
	t_coord			c;
	double			dim;
	int				changed;
}				t_wnd;

typedef struct	s_app
{
	void		*mlx_handle;
	t_wnd		*wnd;
	int			prev_x;
	int			prev_y;
	int			x;
	int			y;
	int			in_zoom;
	int			argc;
	char		**argv;
	t_wnd		*exposed_wnd;
}				t_app;

typedef struct	s_julia_arg
{
	t_coord		*c;
}				t_julia_arg;

typedef struct	s_thread_arg
{
	t_wnd		*wnd;
	int			i;
	int			j;
	double		min_r;
	double		min_i;
	double		step;
	void		*arg;
}				t_thread_arg;

t_app			*init_app(int argc, char **argv);
int				init_img(t_app *app, t_wnd *wnd);
int				init_wnd(t_app	*app);

t_coord			complex_add(t_coord lhs, t_coord rhs);
t_coord			complex_pow(t_coord *coord, double dim);
double			complex_length(t_coord *coord);
t_coord 		build_coord(double r, double i);

t_uint			calc_loop(t_coord coord, t_coord c, double dim);
t_uint			calc_loop_2(t_coord coord, t_coord c);
t_uint			calc_color(t_uint itr);
void			draw_julia(t_wnd *wnd, t_coord min, double step, t_coord c);
void			img_pixel_put(t_wnd *wnd, int x, int y, t_uint color);

void			draw_multibrot(t_wnd *wnd, t_coord min, double step, double dim);

int				julia_key_press(int keycode, void *param);

void			run_pixels(t_thread_arg	*arg, void *(*routine)(void	*));

int				app_expose(void *param);
int				app_loop(void *param);
#endif
