/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:26:17 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:17:54 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long value, unsigned int base)
{
	char				*s;
	unsigned long		ul;

	ul = value;
	if (value < 0)
		ul = -value;
	s = ft_ultoa(ul, base);
	if (value < 0)
		s = ft_strjoinf("-", s, 2);
	return (s);
}
