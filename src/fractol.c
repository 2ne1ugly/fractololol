/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:52:53 by mchi              #+#    #+#             */
/*   Updated: 2019/03/15 12:18:32 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	arg_check(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "julia") != 0 &&
			ft_strcmp(argv[i], "mandelbrot") != 0 &&
			ft_strcmp(argv[i], "multibrot") != 0)
			return (0);
		i++;
	}
	return (1);
}

void	usage_display()
{
	write(1, "julia\nmandelbrot\nmultibrot\n", 27);
}

int 	main(int argc, char **argv)
{
	t_app	*app;
	int		i;
	t_wnd	*wnd;

	if (argc == 1 || !arg_check(argc, argv))
	{
		usage_display();
		return (0);
	}
	if(!(app = init_app(argc, argv)))
		return (0);
	i = 1;
	init_wnd(app);
	mlx_loop_hook(app->mlx_handle, app_loop, app);
	while (i < argc)
	{
		wnd = &app->wnd[i - 1];
		if (ft_strcmp(argv[i], "julia") == 0)
			draw_julia(wnd, wnd->min, wnd->step, wnd->c);
		else
			draw_multibrot(wnd, wnd->min, wnd->step, wnd->dim);
		i++;
	}
	mlx_loop(app->mlx_handle);
}
