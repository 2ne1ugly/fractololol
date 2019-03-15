/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:43:51 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 18:18:36 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	if (num == 0)
		return (0);
	while (*(unsigned char *)ptr1 == *(unsigned char *)ptr2 && num > 1)
	{
		ptr1++;
		ptr2++;
		num--;
	}
	return (*(unsigned char *)ptr1 - *(unsigned char *)ptr2);
}
