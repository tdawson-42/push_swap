/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:32:12 by tdawson           #+#    #+#             */
/*   Updated: 2019/10/21 18:02:23 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!to_find[i])
		return ((char *)str);
	while (str[i] && j++ < c)
	{
		while (str[i] && str[i] == to_find[i] && i + j <= c)
			i++;
		if (to_find[i] == '\0')
			return ((char *)str);
		if (str[i] != to_find[i])
			i = 0;
		str = str + 1;
	}
	return (0);
}
