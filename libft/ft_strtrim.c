/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:04:36 by mchi              #+#    #+#             */
/*   Updated: 2019/02/13 02:59:50 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(void)
{
	char *str;

	str = (char *)malloc(sizeof(char));
	if (str != NULL)
		*str = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	const char	*begin;
	char		*new_string;

	while (*s != '\0' && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	if (*s == '\0')
		return (empty_string());
	begin = s;
	while (*s != '\0')
		s++;
	s--;
	while (s != begin && (*s == ' ' || *s == '\n' || *s == '\t'))
		s--;
	new_string = (char *)malloc(sizeof(char) * (unsigned long)(s - begin + 2));
	if (new_string == NULL)
		return (NULL);
	new_string[s - begin + 1] = '\0';
	ft_strncpy(new_string, begin, (size_t)(s - begin + 1));
	return (new_string);
}
