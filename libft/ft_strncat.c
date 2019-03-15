/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 08:03:11 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 17:54:11 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source, size_t num)
{
	char	*target;

	target = destination;
	while (*target != '\0')
	{
		target++;
	}
	while (*source != '\0' && num > 0)
	{
		*target = *source;
		target++;
		source++;
		num--;
	}
	*target = '\0';
	return (destination);
}
