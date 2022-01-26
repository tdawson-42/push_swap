/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:29:32 by tdawson           #+#    #+#             */
/*   Updated: 2020/01/24 12:33:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_putstrs(int str_num, ...)
{
	va_list		strings;
	const char	*s;

	va_start(strings, str_num);
	while (str_num-- > 0)
	{
		s = va_arg(strings, const char *);
		if (s)
			ft_putstr(s);
	}
	va_end(strings);
}
