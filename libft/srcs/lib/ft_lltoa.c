/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:26:17 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 17:33:10 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long value, unsigned int base)
{
	char				*s;
	unsigned long long	ull;

	ull = value;
	if (value < 0)
		ull = -value;
	s = ft_ulltoa(ull, base);
	if (value < 0)
		s = ft_strjoinf("-", s, 2);
	return (s);
}
