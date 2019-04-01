/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:21:59 by mchi              #+#    #+#             */
/*   Updated: 2019/03/30 12:55:41 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	join_pool(pthread_t	*thread_pool, int num)
{
	int		i;
	void	*hold;

	i = 0;
	while (i < num)
	{
		pthread_join(thread_pool[i], (void **)&hold);
		i++;
	}
}

void	init_arg(t_local_arg *local_arg_arr, t_thread_arg *arg, int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		local_arg_arr[i].i = i;
		local_arg_arr[i].thread_arg = arg;
		i++;
	}
}

void	run_pixels(t_thread_arg	*arg, void *(*routine)(void	*))
{
	t_uint		pool_count;
	pthread_t	thread_pool[N_THREAD];
	t_local_arg	local_arg_arr[N_THREAD];

	pool_count = 0;
	init_arg(local_arg_arr, arg, N_THREAD);
	while (pool_count < N_THREAD)
	{
		pthread_create(&thread_pool[pool_count], NULL, routine,
			&local_arg_arr[pool_count]);
		pool_count++;
	}
	join_pool(thread_pool, pool_count);
}