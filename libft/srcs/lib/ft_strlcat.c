/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:33:28 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:38:38 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (dest[i] != '\0')
		++i;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (size <= i)
		res += size;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
