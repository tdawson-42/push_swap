/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:22:27 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:43:15 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, unsigned int base)
{
	char		*tab;
	char		*s;
	long		n;
	size_t		len;

	if (base < 2 || base > 16)
		return (0);
	tab = "0123456789ABCDEF";
	if (value < 0)
		n = -(long)value;
	else
		n = value;
	len = ft_numlen_base(n, base) + (value < 0 && base == 10);
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	while (len--)
	{
		s[len] = tab[n % base];
		n /= base;
	}
	if (value < 0 && base == 10)
		s[0] = '-';
	return (s);
}
