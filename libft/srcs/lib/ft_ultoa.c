/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:22:27 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:43:17 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long value, unsigned int base)
{
	char		*tab;
	char		*s;
	size_t		len;

	if (base < 2 || base > 16)
		return (0);
	tab = "0123456789ABCDEF";
	len = ft_numlen_base(value, base);
	s = ft_strnew(len);
	while (len--)
	{
		s[len] = tab[value % base];
		value /= base;
	}
	return (s);
}
