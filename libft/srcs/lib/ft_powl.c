/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:26:07 by tdawson           #+#    #+#             */
/*   Updated: 2020/01/30 18:26:14 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_powl(long double base, long double exponent)
{
	long double		n;

	n = base;
	while (--exponent)
		n *= base;
	return (n);
}
