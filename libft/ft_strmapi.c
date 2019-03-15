/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:37:20 by mchi              #+#    #+#             */
/*   Updated: 2019/02/13 02:57:47 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	char			*target;
	unsigned int	index;
	size_t			length;

	length = ft_strlen(s);
	new_string = malloc(sizeof(char) * (length + 1));
	if (new_string == NULL)
		return (NULL);
	target = new_string;
	index = 0;
	while (*s != '\0')
	{
		*target = f(index, *s);
		target++;
		s++;
		index++;
	}
	*target = '\0';
	return (new_string);
}
