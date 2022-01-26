/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:11:45 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:39:53 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
			return ((char *)str + len);
		len--;
	}
	return (0);
}
