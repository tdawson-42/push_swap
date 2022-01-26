/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:48:31 by tdawson           #+#    #+#             */
/*   Updated: 2020/01/24 12:36:00 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest)
	{
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else if (src > dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
