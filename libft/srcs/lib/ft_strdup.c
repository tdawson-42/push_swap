/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:03:27 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:44:10 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(ft_strlen(src));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
