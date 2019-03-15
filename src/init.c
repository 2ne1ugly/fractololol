/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:53:35 by mchi              #+#    #+#             */
/*   Updated: 2019/03/15 12:30:53 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		hook_wnd_functions(t_wnd *wnd)
{
	mlx_expose_hook(wnd->wnd_handle, app_expose, wnd);
	if (ft_strcmp(wnd->name, "julia") == 0)
		mlx_hook(wnd->wnd_handle, 2, 0, julia_key_press, wnd);	
//	mlx_hook(app->wnd_handle, 4, 0, app_mouse_press, app);
//	mlx_hook(app->wnd_handle, 5, 0, app_mouse_release, app);
//	mlx_hook(app->wnd_handle, 6, 0, app_mouse_move, app);
}


int			init_img(t_app *app, t_wnd *wnd)
{
	wnd->img.ptr =
		mlx_new_image(app->mlx_handle, wnd->width, wnd->height);
	if (wnd->img.ptr == NULL)
		return (0);
	wnd->img.data_addr =
		mlx_get_data_addr(wnd->img.ptr, &wnd->img.bpp,
			&wnd->img.sl, &wnd->img.endian);
	wnd->img.bpp /= 8;
	return (1);
}

int			set_individual_data(t_wnd *wnd)
{
	wnd->min = build_coord(-2, -2);
	wnd->step = 0.005;
	if (ft_strcmp(wnd->name, "julia") == 0)
		wnd->c = build_coord(-0.4, 0.6);
	else
		wnd->dim = 2;
	return (1);
}

int			init_wnd(t_app	*app)
{
	int	i;

	i = 1;
	app->wnd = malloc(sizeof(t_wnd) * (app->argc - 1));
	app->exposed_wnd = app->wnd;
	while (i < app->argc)
	{
		app->wnd[i - 1].wnd_handle =
			mlx_new_window(app->mlx_handle, 800, 800, app->argv[i]);
		if (app->wnd[i - 1].wnd_handle == NULL)
			return (0);
		app->wnd[i - 1].name = app->argv[i];
		app->wnd[i - 1].width = 40;
		app->wnd[i - 1].height = 40;
		app->wnd[i - 1].app = app;
		app->wnd[i - 1].changed = 0;
		if (!init_img(app, &app->wnd[i - 1]))
			return (0);
		set_individual_data(&app->wnd[i - 1]);
		hook_wnd_functions(&app->wnd[i - 1]);
		i++;
	}
	return (1);
}

t_app		*init_app(int argc, char **argv)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	if (app == NULL)
		return (NULL);
	app->mlx_handle = mlx_init();
	if (app->mlx_handle == NULL)
		return (NULL);
	app->in_zoom = 0;
	app->argc = argc;
	app->argv = argv;
	return (app);
}
