/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:27:29 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 17:17:23 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	nbr;
	int						sign;

	sign = 1;
	nbr = 0;
	while (*str && ft_isspace(*str))
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - 48);
		++str;
	}
	if (nbr > 9223372036854775807)
		return ((sign < 0) - 1);
	return (nbr * sign);
}
