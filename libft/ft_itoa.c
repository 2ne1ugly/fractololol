/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:28:44 by mchi              #+#    #+#             */
/*   Updated: 2019/02/19 12:13:56 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*result;
	int		index;
	int		is_negative;

	index = ft_count_digit(n);
	result = (char *)malloc(sizeof(char) * (unsigned long)(index + 1));
	if (result == NULL)
		return (NULL);
	result[index--] = '\0';
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		result[0] = '-';
	}
	while (index >= is_negative)
	{
		if (!is_negative)
			result[index] = (n % 10 + '0');
		else
			result[index] = (-1 * (n % 10) + '0');
		n /= 10;
		index--;
	}
	return (result);
}
