/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:18:38 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:25:54 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	long_numlen(unsigned long long n)
{
	if (n < 100000000000L)
		return (11);
	if (n < 1000000000000L)
		return (12);
	if (n < 10000000000000L)
		return (13);
	if (n < 100000000000000L)
		return (14);
	if (n < 1000000000000000L)
		return (15);
	if (n < 10000000000000000L)
		return (16);
	if (n < 100000000000000000L)
		return (17);
	if (n < 1000000000000000000L)
		return (18);
	if (n < 10000000000000000000UL)
		return (19);
	return (20);
}

size_t	ft_numlen(unsigned long long n)
{
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	if (n < 10000000000L)
		return (10);
	return (long_numlen(n));
}
