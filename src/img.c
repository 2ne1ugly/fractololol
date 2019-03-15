/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:08:47 by mchi              #+#    #+#             */
/*   Updated: 2019/03/04 21:21:10 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(t_wnd *wnd, int x, int y, t_uint color)
{
	if (x < 0 || y < 0 || (t_uint)x >= wnd->width || (t_uint)y >= wnd->height)
		return ;
	*(int *)(wnd->img.data_addr + (x + y * wnd->width) * wnd->img.bpp) = color;
}
