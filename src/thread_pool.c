/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:21:59 by mchi              #+#    #+#             */
/*   Updated: 2019/03/15 12:12:19 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	join_pool(pthread_t	*thread_pool, int num)
{
	int	i;
	int	*hold;

	i = 0;
	hold = malloc(sizeof(int));
	while (i < num)
	{
		pthread_join(thread_pool[i], (void **)&hold);
		i++;
	}
	free(hold);
}

void	run_pixels(t_thread_arg	*arg, void *(*routine)(void	*))
{
	t_uint		i;
	t_uint		j;
	pthread_t	*thread_pool;

	i = 0;
	thread_pool = malloc(sizeof(pthread_t) * arg->wnd->height * arg->wnd->width);
	while (i < arg->wnd->height)
	{
		arg->i = i;
		j = 0;
		while (j < arg->wnd->width)
		{
			arg->j = j;
			pthread_create(&thread_pool[i * arg->wnd->width + j],
				NULL, routine, &arg);
			j++;
		}
		i++;
	}
	join_pool(thread_pool, arg->wnd->height * arg->wnd->width);
	free(thread_pool);
}