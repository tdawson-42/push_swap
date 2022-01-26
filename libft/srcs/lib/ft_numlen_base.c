/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:16:38 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:25:27 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(unsigned long long n, unsigned int base)
{
	size_t			len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
