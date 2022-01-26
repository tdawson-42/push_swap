/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:00:15 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 17:22:18 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	magic_round(double d)
{
	d += 6755399441055744;
	d -= 6755399441055744;
	return (d);
}

static char	*create_str(long long i, long long d, unsigned int precis)
{
	char		*s;
	char		*tmp;
	size_t		len;
	int			round;

	len = ft_numlen(d);
	round = (len > precis);
	s = ft_strnew(ft_numlen(i) + precis + 1);
	tmp = ft_lltoa(i + round, 10);
	ft_strcat(s, tmp);
	free(tmp);
	ft_strcat(s, ".");
	if (len < precis)
		while (len < precis--)
			ft_strcat(s, "0");
	tmp = ft_lltoa(d, 10);
	ft_strcat(s, tmp + round);
	free(tmp);
	return (s);
}

char	*ft_ftoa(long double n, unsigned int precision)
{
	long long	i;
	long long	d;

	if (n < 0)
		n = -n;
	if (precision == 0)
		return (ft_lltoa(magic_round(n), 10));
	i = (long long)n;
	n -= (long long)n;
	n *= ft_powl(10.0, precision);
	d = (long long)(n + 0.5);
	return (create_str(i, d, precision));
}
