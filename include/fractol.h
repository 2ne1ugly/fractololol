/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:57:34 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 16:54:44 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define PI 3.14159265359
# define MAGENTA 0x00FF00
# define N_THREAD 16

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
	int				dim;
	int				changed;
	int				mode;
	int				prev_x;
	int				prev_y;
	int				x;
	int				y;
	int				change_val;
}				t_wnd;

typedef struct	s_app
{
	void		*mlx_handle;
	t_wnd		*wnd;
	int			prev_x;
	int			prev_y;
	int			x;
	int			y;
	int			argc;
	char		**argv;
	t_wnd		*exposed_wnd;
}				t_app;

typedef struct	s_thread_arg
{
	t_wnd		*wnd;
	double		min_r;
	double		min_i;
	double		step;
	void		*render_arg;
}				t_thread_arg;

typedef struct	s_local_arg
{
	int				i;
	t_thread_arg	*thread_arg;
}				t_local_arg;

t_app			*init_app(int argc, char **argv);
int				init_img(t_app *app, t_wnd *wnd);
int				init_wnd(t_app	*app);

void			complex_add(t_coord *lhs, t_coord rhs);
t_coord			complex_pow(t_coord *coord, int dim);
double			complex_length(t_coord *coord);

t_uint			calc_loop(t_coord *coord, t_coord c, int dim);
t_uint			calc_loop_2(t_coord *coord, t_coord c);
int				calc_color(t_uint itr, t_coord *zn, int mode);
void			draw_julia(t_wnd *wnd, t_coord min, double step, t_coord c);
void			img_pixel_put(t_wnd *wnd, int x, int y, t_uint color);

void			draw_multibrot(t_wnd *wnd, t_coord min, double step, int dim);

int				julia_mouse_move(int x, int y, void *param);
int				mandelia_key_press(int keycode, void *param);
int 			mandelia_mouse_press(int button, int x, int y, void *param);
int				multibrot_key_press(int keycode, void *param);
int 			multibrot_mouse_press(int button, int x, int y, void *param);

void			run_pixels(t_thread_arg	*arg, void *(*routine)(void	*));

int				app_expose(void *param);
int				app_loop(void *param);
#endif
