/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 06:59:08 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 15:30:42 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int source, size_t num)
{
	unsigned char *target;

	target = (unsigned char *)destination;
	while (num > 0)
	{
		*target = (unsigned char)source;
		target++;
		num--;
	}
	return (destination);
}
