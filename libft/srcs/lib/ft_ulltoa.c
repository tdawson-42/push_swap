/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:02:17 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:43:12 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(unsigned long long value, unsigned int base)
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
